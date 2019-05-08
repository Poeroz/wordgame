/**
 * @file playerfailedwidget.cpp
 *
 * @brief 闯关失败的界面。
 * @author 房庆凯 - 2017211131
 */

#include "playerfailedwidget.h"
#include "ui_playerfailedwidget.h"

playerFailedWidget::playerFailedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerFailedWidget) {
    ui->setupUi(this);
}

playerFailedWidget::~playerFailedWidget() {
    delete ui;
}

void playerFailedWidget::on_retryBtn_clicked() {
    emit failedToGaming();
}

void playerFailedWidget::on_returnBtn_clicked() {
    emit failedToChLevel();
}
