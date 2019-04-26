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
