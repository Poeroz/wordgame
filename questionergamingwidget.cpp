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
        QMessageBox::warning(this, tr("提示"), tr("该单词已存在"), QMessageBox::Ok);
        ui->wordLineEdit->clear();
        ui->wordLineEdit->setFocus();
    }
    else {
        addWorddb(newWord);
    }
}
