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
    connect(gaming, SIGNAL(gamingToPassed(int)), this, SLOT(switchGamingToPassed(int)));
    connect(chLevel, SIGNAL(chLevelToReady()), this, SLOT(switchChLevelToReady()));
    connect(chLevel, SIGNAL(chLevelToGaming(int)), this, SLOT(switchChLevelToGaming(int)));
    connect(passed, SIGNAL(passedToGaming()), this, SLOT(switchPassedToGaming()));
    connect(passed, SIGNAL(passedToChLevel()), this, SLOT(switchPassedToChLevel()));
    connect(failed, SIGNAL(failedToGaming()), this, SLOT(switchFailedToGaming()));
    connect(failed, SIGNAL(failedToChLevel()), this, SLOT(switchFailedToChLevel()));
    connect(this, SIGNAL(updatePlayerInfo(const player&)), ready, SLOT(refreshPlayer(const player&)));
    connect(ready, SIGNAL(exitGame()), this, SLOT(closeWindow()));
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

void playerWindow::switchGamingToPassed(int currentLevel) {
    gaming->hide();
    gaming->stop();
    passed->show();

    /* 根据当前通过关卡，更新已闯关卡数、经验值、等级 */
    currentPlayer->setLevelCnt(qMax(currentPlayer->getLevelCnt(), currentLevel));
    int needExp = currentPlayer->getGrade() * 5;
    int restExp = currentLevel + currentPlayer->getExperience();
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

void playerWindow::closeWindow() {
    this->close();
}

