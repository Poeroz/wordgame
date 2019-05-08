/**
 * @file playerreadywidget.cpp
 *
 * @brief 闯关者准备界面。
 * @author 房庆凯 - 2017211131
 */

#include "playerreadywidget.h"
#include "ui_playerreadywidget.h"

playerReadyWidget::playerReadyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerReadyWidget) {
    ui->setupUi(this);
}

playerReadyWidget::~playerReadyWidget() {
    delete ui;
}

void playerReadyWidget::init(player user) {
    ui->nicknameShow->setText(user.getNickname());
    ui->gradeShow->setText(QString::number(user.getGrade()));
    ui->levelShow->setText(QString::number(user.getLevelCnt()));
    ui->expShow->setText(QString::number(user.getExperience()));
}

void playerReadyWidget::on_allUserBtn_clicked() {
    emit readyToAllUser();
}

void playerReadyWidget::on_startBtn_clicked() {
    emit readyToChLevel();
}

void playerReadyWidget::refreshPlayer(const player &newPlayer) {
    ui->gradeShow->setText(QString::number(newPlayer.getGrade()));
    ui->levelShow->setText(QString::number(newPlayer.getLevelCnt()));
    ui->expShow->setText(QString::number(newPlayer.getExperience()));
}
