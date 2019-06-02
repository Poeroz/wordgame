/**
 * @file playerfilterdialog.cpp
 *
 * @brief 闯关者条件筛选对话框。
 * @author 房庆凯 - 2017211131
 */

#include "playerfilterdialog.h"
#include "ui_playerfilterdialog.h"

playerFilterDialog::playerFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playerFilterDialog) {
    ui->setupUi(this);
}

playerFilterDialog::~playerFilterDialog() {
    delete ui;
}

void playerFilterDialog::on_okBtn_clicked() {
    QString name = ui->nicknameLineEdit->text();
    QString grade = ui->gradeLineEdit->text();
    QString level = ui->levelCntLineEdit->text();
    QString exp = ui->expLineEdit->text();

    /* 构造筛选信息的数据库条件语句 */
    QString str = QString("role = %1").arg(PLAYER);
    if (name != "") {
        str.append(QString(" and nickname = '%1'").arg(name));
    }
    if (grade != "") {
        str.append(QString(" and grade = %1").arg(grade));
    }
    if (level != "") {
        str.append(QString(" and levelCnt = %1").arg(level));
    }
    if (exp != "") {
        str.append(QString(" and experience = %1").arg(exp));
    }

    /* 发送条件语句给父窗口 */
    emit playerSendData(str);
    this->accept();
}
