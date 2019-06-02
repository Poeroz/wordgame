/**
 * @file playerfilterdialog.cpp
 *
 * @brief 出题者条件筛选对话框。
 * @author 房庆凯 - 2017211131
 */

#include "questionerfilterdialog.h"
#include "ui_questionerfilterdialog.h"

questionerFilterDialog::questionerFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::questionerFilterDialog) {
    ui->setupUi(this);
}

questionerFilterDialog::~questionerFilterDialog() {
    delete ui;
}

void questionerFilterDialog::on_okBtn_clicked() {
    QString name = ui->nicknameLineEdit->text();
    QString grade = ui->gradeLineEdit->text();
    QString qCnt = ui->questionCntLineEdit->text();

    /* 构造筛选信息的数据库条件语句 */
    QString str = QString("role = %1").arg(QUESTIONER);
    if (name != "") {
        str.append(QString(" and nickname = '%1'").arg(name));
    }
    if (grade != "") {
        str.append(QString(" and grade = %1").arg(grade));
    }
    if (qCnt != "") {
        str.append(QString(" and questionCnt = %1").arg(qCnt));
    }

    /* 发送条件语句给父窗口 */
    emit questionerSendData(str);
    this->accept();
}
