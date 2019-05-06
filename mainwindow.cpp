/**
 * @file mainwindow.cpp
 *
 * @brief 主窗口。
 * @author 房庆凯 - 2017211131
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    /* 初始化用户、单词数据库 */
    userdbManager::initUserdb();
    worddbManager::initWorddb();

    /* 初始化注册、登录窗口，并在最初显示登录窗口 */
    signIn = new signInWidget(this);
    signUp = new signUpWidget(this);
    signIn->showAgain();
    signUp->hide();

    /* 连接信号和槽 */
    connect(signIn, SIGNAL(toSignUp()), this, SLOT(switchToSignUp()));
    connect(signUp, SIGNAL(toSignIn()), this, SLOT(switchToSignIn()));
    connect(signIn, SIGNAL(closeWindow()), this, SLOT(exitProgram()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::switchToSignIn() {
    signUp->hide();
    signIn->showAgain();
}

void MainWindow::switchToSignUp() {
    signIn->hide();
    signUp->showAgain();
}

void MainWindow::exitProgram() {
    this->close();
}
