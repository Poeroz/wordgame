#include "questionerreadywidget.h"
#include "ui_questionerreadywidget.h"

questionerReadyWidget::questionerReadyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::questionerReadyWidget) {
    ui->setupUi(this);
}

questionerReadyWidget::~questionerReadyWidget() {
    delete ui;
}

void questionerReadyWidget::init(questioner user) {
    ui->nicknameShow_2->setText(user.getNickname());
    ui->gradeShow_2->setText(QString::number(user.getGrade()));
    ui->questionCntShow->setText(QString::number(user.getQuestionCnt()));
}

void questionerReadyWidget::on_allUserBtn_2_clicked() {
    emit readyToAllUser();
}

void questionerReadyWidget::on_startBtn_2_clicked() {
    emit readyToGaming();
}

void questionerReadyWidget::refreshQuestioner(const questioner &newQuestioner) {
    ui->gradeShow_2->setText(QString::number(newQuestioner.getGrade()));
    ui->questionCntShow->setText(QString::number(newQuestioner.getQuestionCnt()));
}

void questionerReadyWidget::on_exitBtn_clicked() {
    emit exitGame();
}
