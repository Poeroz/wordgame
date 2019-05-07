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
