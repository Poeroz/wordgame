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

    /* 初始化三个子窗口，并显示准备窗口 */
    gaming = new playerGamingWidget(this);
    ready = new playerReadyWidget(this);
    allUser = new allUserWidget(this);
    ready->show();
    gaming->hide();
    allUser->hide();

    /* 连接信号和槽 */
    connect(ready, SIGNAL(readyToAllUser()), this, SLOT(switchReadyToAllUser()));
    connect(ready, SIGNAL(readyToGaming()), this, SLOT(switchReadyToGaming()));
    connect(allUser, SIGNAL(allUserToReady()), this, SLOT(switchAllUserToReady()));
    connect(gaming, SIGNAL(gamingToReady()), this, SLOT(switchGamingToReady()));
}

playerWindow::~playerWindow() {
    delete ui;
}

void playerWindow::init(player user) {
    ready->init(user);
}

void playerWindow::switchReadyToAllUser() {
    ready->hide();
    allUser->show();
    allUser->init();
}

void playerWindow::switchReadyToGaming() {
    ready->hide();
    gaming->show();
    gaming->init();
}

void playerWindow::switchAllUserToReady() {
    allUser->hide();
    ready->show();
}

void playerWindow::switchGamingToReady() {
    gaming->hide();
    gaming->stop();
    ready->show();
}
