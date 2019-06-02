/**
 * @file playerwindow.cpp
 *
 * @brief 闯关者游戏主窗口。
 * @author 房庆凯 - 2017211131
 */

#include "playerwindow.h"
#include "ui_playerwindow.h"

playerWindow::playerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::playerWindow) {
    ui->setupUi(this);
    this->setFixedSize(350, 400);
}

playerWindow::~playerWindow() {
    delete ui;
}

void playerWindow::init(player user) {
    currentPlayer = new player(user);

    /* 初始化三个子窗口，并显示准备窗口 */
    gaming = new playerGamingWidget(this);
    ready = new playerReadyWidget(this);
    allUser = new allUserWidget(this);
    chLevel = new chooseLevelWidget(this);
    passed = new playerPassedWidget(this);
    failed = new playerFailedWidget(this);
    match = new matchGamingWidget(this);
    endMatch = new endMatchWidget(this);
    endMatch->hide();
    match->hide();
    ready->show();
    ready->init(user);
    gaming->hide();
    allUser->hide();
    chLevel->hide();
    chLevel->init(currentPlayer->getLevelCnt());
    passed->hide();
    failed->hide();

    /* 连接信号和槽 */
    connect(ready, SIGNAL(readyToAllUser()), this, SLOT(switchReadyToAllUser()));
    connect(ready, SIGNAL(readyToChLevel()), this, SLOT(switchReadyToChLevel()));
    connect(allUser, SIGNAL(allUserToReady()), this, SLOT(switchAllUserToReady()));
    connect(gaming, SIGNAL(gamingToChLevel()), this, SLOT(switchGamingToChLevel()));
    connect(gaming, SIGNAL(gamingToFailed()), this, SLOT(switchGamingToFailed()));
    connect(gaming, SIGNAL(gamingToPassed(int, int)), this, SLOT(switchGamingToPassed(int, int)));
    connect(chLevel, SIGNAL(chLevelToReady()), this, SLOT(switchChLevelToReady()));
    connect(chLevel, SIGNAL(chLevelToGaming(int)), this, SLOT(switchChLevelToGaming(int)));
    connect(passed, SIGNAL(passedToGaming()), this, SLOT(switchPassedToGaming()));
    connect(passed, SIGNAL(passedToChLevel()), this, SLOT(switchPassedToChLevel()));
    connect(failed, SIGNAL(failedToGaming()), this, SLOT(switchFailedToGaming()));
    connect(failed, SIGNAL(failedToChLevel()), this, SLOT(switchFailedToChLevel()));
    connect(this, SIGNAL(updatePlayerInfo(const player&)), ready, SLOT(refreshPlayer(const player&)));
    connect(ready, SIGNAL(exitGame()), this, SLOT(closeWindow()));
    connect(ready, SIGNAL(matchGame()), this, SLOT(switchReadyToMatch()));
    connect(match, SIGNAL(endGame(bool)), this, SLOT(switchMatchToEnd(bool)));
    connect(match, SIGNAL(cancelMatch()), this, SLOT(switchMatchToReady()));
    connect(endMatch, SIGNAL(endToReady()), this, SLOT(switchEndToReady()));
}

void playerWindow::cancelMatch() {
    QJsonObject json;
    json["type"] = "cancelMatch";
    json["usr"] = currentPlayer->getUsername();
    QJsonObject rec = tcpMan.sendData(json);
    if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
}

void playerWindow::switchReadyToAllUser() {
    ready->hide();
    allUser->show();
    allUser->init();
}

void playerWindow::switchReadyToChLevel() {
    ready->hide();
    chLevel->show();
}

void playerWindow::switchAllUserToReady() {
    allUser->hide();
    ready->show();
}

void playerWindow::switchChLevelToReady() {
    chLevel->hide();
    ready->show();
}

void playerWindow::switchChLevelToGaming(int levelId) {
    chLevel->hide();
    gaming->show();
    gaming->init(levelId);
}

void playerWindow::switchGamingToChLevel() {
    gaming->hide();
    gaming->stop();
    chLevel->show();
}

void playerWindow::switchGamingToFailed() {
    gaming->hide();
    gaming->stop();
    failed->show();
}

void playerWindow::switchGamingToPassed(int currentLevel, int plusExp) {
    gaming->hide();
    gaming->stop();
    passed->show();

    /* 根据当前通过关卡，更新已闯关卡数、经验值、等级 */
    currentPlayer->setLevelCnt(qMax(currentPlayer->getLevelCnt(), currentLevel));
    int needExp = currentPlayer->getGrade() * 5;
    int restExp = plusExp + currentPlayer->getExperience();
    while (restExp >= needExp) {
        restExp -= needExp;
        currentPlayer->setGrade(currentPlayer->getGrade() + 1);
        needExp = currentPlayer->getGrade() * 5;
    }
    currentPlayer->setExperience(restExp);

    /* 更新选择关卡界面 */
    chLevel->init(currentPlayer->getLevelCnt());

    /* 更新数据库里的闯关者信息 */
    userdbManager man;
    man.updatePlayer(*currentPlayer);

    /* 更新准备界面显示的闯关者信息 */
    emit updatePlayerInfo(*currentPlayer);
}

void playerWindow::switchPassedToGaming() {
    passed->hide();
    gaming->init();
    gaming->show();
}

void playerWindow::switchPassedToChLevel() {
    passed->hide();
    chLevel->show();
}

void playerWindow::switchFailedToGaming() {
    failed->hide();
    gaming->init();
    gaming->show();
}

void playerWindow::switchFailedToChLevel() {
    failed->hide();
    chLevel->show();
}

void playerWindow::switchMatchToEnd(bool pass) {
    QJsonObject json;
    json["type"] = "endMatch";
    json["usr"] = currentPlayer->getUsername();
    json["pass"] = pass ? 1 : -1;
    bool winState;
    int getExp;

    QJsonObject rec = tcpMan.sendData(json);
    if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
        qDebug() << "failed";
    }
    else {
        winState = rec["win"].toBool();
        getExp = rec["exp"].toInt();
        int plusExp = rec["exp"].toInt();
        int needExp = currentPlayer->getGrade() * 5;
        int restExp = plusExp + currentPlayer->getExperience();
        while (restExp >= needExp) {
            restExp -= needExp;
            currentPlayer->setGrade(currentPlayer->getGrade() + 1);
            needExp = currentPlayer->getGrade() * 5;
        }
        currentPlayer->setExperience(restExp);

        userdbManager man;
        man.updatePlayer(*currentPlayer);

        emit updatePlayerInfo(*currentPlayer);
    }

    match->hide();
    endMatch->show();
    endMatch->init(winState, getExp);
}

void playerWindow::switchMatchToReady() {
    match->hide();
    ready->show();
}

void playerWindow::switchReadyToMatch() {
    ready->hide();
    match->show();
    match->init(tr("正在匹配..."));
    QJsonObject json;
    json["type"] = "matchPlayer";
    json["usr"] = currentPlayer->getUsername();
    int cnt = 0;
    while (true) {
        if (++cnt == 50) {
            ready->show();
            match->hide();
            cancelMatch();
            break;
        };
        QJsonObject rec = tcpMan.sendData(json);
        if (!rec.contains(STATUS) || rec[STATUS].toString() == FAILED) {
            qDebug() << "failed";
        }
        else {
            if (rec["matchStatus"].toBool()) {
                QVector<QString> wordlist;
                QJsonArray tmpArray = rec["wordlist"].toArray();
                for (int index = 0; index < tmpArray.size(); index++) {
                    QJsonObject tmpObject = tmpArray[index].toObject();
                    wordlist.push_back(tmpObject["text"].toString());
                }
                match->start(wordlist);
                break;
            }
        }
        QElapsedTimer t;
        t.start();
        while(t.elapsed() < 100)
            QCoreApplication::processEvents();
    }
}

void playerWindow::switchEndToReady() {
    endMatch->hide();
    ready->show();
}

void playerWindow::closeWindow() {
    this->close();
}


