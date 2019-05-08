/**
 * @file playerpassedwidget.cpp
 *
 * @brief 闯关成功的界面。
 * @author 房庆凯 - 2017211131
 */

#include "playerpassedwidget.h"
#include "ui_playerpassedwidget.h"

playerPassedWidget::playerPassedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerPassedWidget) {
    ui->setupUi(this);
}

playerPassedWidget::~playerPassedWidget() {
    delete ui;
}

void playerPassedWidget::on_nextBtn_clicked() {
    emit passedToGaming();
}

void playerPassedWidget::on_returnBtn_clicked() {
    emit passedToChLevel();
}
