/**
 * @file questionergamingwidget.cpp
 *
 * @brief 出题者游戏中界面。
 * @author 房庆凯 - 2017211131
 */

#include "questionergamingwidget.h"
#include "ui_questionergamingwidget.h"

questionerGamingWidget::questionerGamingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::questionerGamingWidget) {
    ui->setupUi(this);
}

questionerGamingWidget::~questionerGamingWidget() {
    delete ui;
}

void questionerGamingWidget::on_okBtn_clicked() {
    QString newWord = ui->wordLineEdit->text();
    worddbManager man;
    if (man.queryWorddb(newWord)) {                             /* 查询单词是否存在 */
        ui->statusLabel->setText(tr("该单词已存在！"));
        ui->wordLineEdit->clear();
        ui->wordLineEdit->setFocus();
    }
    else {
        man.addWorddb(newWord);                                 /* 添加单词到数据库 */
        ui->statusLabel->setText(tr("添加成功！"));
        ui->wordLineEdit->clear();
        ui->wordLineEdit->setFocus();
        emit addNewWord();
    }
}

void questionerGamingWidget::on_endgameBtn_clicked() {
    emit gamingToReady();
}

void questionerGamingWidget::init() {
    ui->wordLineEdit->clear();
}
