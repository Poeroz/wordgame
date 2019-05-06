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

    /* 初始化三个子窗口，并显示准备窗口 */
    ready = new questionerReadyWidget(this);
    gaming = new questionerGamingWidget(this);
    allUser = new allUserWidget(this);
    ready->show();
    gaming->hide();
    allUser->hide();

    connect(ready, SIGNAL(readyToAllUser()), this, SLOT(switchReadyToAllUser()));
    connect(ready, SIGNAL(readyToGaming()), this, SLOT(switchReadyToGaming()));
    connect(allUser, SIGNAL(allUserToReady()), this, SLOT(switchAllUserToReady()));
    connect(gaming, SIGNAL(gamingToReady()), this, SLOT(switchGamingToReady()));

}

questionerWindow::~questionerWindow() {
    delete ui;
}

void questionerWindow::init(questioner user) {
    ready->init(user);
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
