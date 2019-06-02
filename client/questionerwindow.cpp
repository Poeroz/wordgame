/**
 * @file questionerwindow.cpp
 *
 * @brief 出题者游戏主窗口。
 * @author 房庆凯 - 2017211131
 */

#include "questionerwindow.h"
#include "ui_questionerwindow.h"

questionerWindow::questionerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::questionerWindow) {
    ui->setupUi(this);
    this->setFixedSize(350, 400);
}

questionerWindow::~questionerWindow() {
    delete ui;
}

void questionerWindow::init(questioner user) {
    currentQuestioner = new questioner(user);

    /* 初始化三个子窗口，并显示准备窗口 */
    ready = new questionerReadyWidget(this);
    gaming = new questionerGamingWidget(this);
    allUser = new allUserWidget(this);
    ready->show();
    ready->init(user);
    gaming->hide();
    allUser->hide();

    /* 连接信号和槽 */
    connect(ready, SIGNAL(readyToAllUser()), this, SLOT(switchReadyToAllUser()));
    connect(ready, SIGNAL(readyToGaming()), this, SLOT(switchReadyToGaming()));
    connect(allUser, SIGNAL(allUserToReady()), this, SLOT(switchAllUserToReady()));
    connect(gaming, SIGNAL(gamingToReady()), this, SLOT(switchGamingToReady()));
    connect(gaming, SIGNAL(addNewWord()), this, SLOT(updateQuestioner()));
    connect(this, SIGNAL(updateQuestionerInfo(const questioner&)), ready, SLOT(refreshQuestioner(const questioner&)));
    connect(ready, SIGNAL(exitGame()), this, SLOT(closeWindow()));
}

void questionerWindow::switchReadyToAllUser() {
    ready->hide();
    allUser->show();
    allUser->init();
}

void questionerWindow::switchReadyToGaming() {
    ready->hide();
    gaming->show();
    gaming->init();
}

void questionerWindow::switchAllUserToReady() {
    allUser->hide();
    ready->show();
}

void questionerWindow::switchGamingToReady() {
    gaming->hide();
    ready->show();
}

void questionerWindow::updateQuestioner() {
    int currentGrade = currentQuestioner->getGrade();
    int currentCnt = currentQuestioner->getQuestionCnt();

    currentQuestioner->setQuestionCnt(currentCnt + 1);
    if (currentCnt + 1 == (currentGrade + 1) * (currentGrade + 2) / 2) {
        currentQuestioner->setGrade(currentGrade + 1);
    }

    userdbManager man;
    man.updateQuestioner(*currentQuestioner);

    emit updateQuestionerInfo(*currentQuestioner);
}

void questionerWindow::closeWindow() {
    this->close();
}
