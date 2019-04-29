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
    if (queryWorddb(newWord)) {
        ui->statusLabel->setText(tr("该单词已存在！"));
        ui->wordLineEdit->clear();
        ui->wordLineEdit->setFocus();
    }
    else {
        addWorddb(newWord);
        ui->statusLabel->setText(tr("添加成功！"));
        ui->wordLineEdit->clear();
        ui->wordLineEdit->setFocus();
    }
}

void questionerGamingWidget::on_pushButton_clicked() {
    this->close();
}
