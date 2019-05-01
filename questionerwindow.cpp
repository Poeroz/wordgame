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
}

questionerWindow::~questionerWindow() {
    delete ui;
}

void questionerWindow::init(questioner user) {
    ui->nicknameShow->setText(user.getNickname());
    ui->gradeShow->setText(QString::number(user.getGrade()));
    ui->questionCntShow->setText(QString::number(user.getQuestionCnt()));
}

void questionerWindow::on_allUserBtn_clicked() {
    allUserWidget *widget = new allUserWidget;
    widget->show();
}

void questionerWindow::on_startBtn_clicked() {
    questionerGamingWidget *widget = new questionerGamingWidget();
    widget->show();
}
