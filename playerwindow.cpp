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
}

playerWindow::~playerWindow() {
    delete ui;
}

void playerWindow::init(player user) {
    ui->nicknameShow->setText(user.getNickname());
    ui->gradeShow->setText(QString::number(user.getGrade()));
    ui->levelShow->setText(QString::number(user.getLevelCnt()));
    ui->expShow->setText(QString::number(user.getExperience()));
}

void playerWindow::on_allUserBtn_clicked() {
    allUserWidget *widget = new allUserWidget;
    widget->show();
}

void playerWindow::on_startBtn_clicked() {
    playerGamingWidget *widget = new playerGamingWidget();
    widget->show();
}
