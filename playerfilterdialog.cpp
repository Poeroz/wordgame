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

    emit playerSendData(str);
    this->accept();
}
