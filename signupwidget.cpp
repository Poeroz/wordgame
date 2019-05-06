/**
 * @file signupwidget.cpp
 *
 * @brief 注册窗口。
 * @author 房庆凯 - 2017211131
 */

#include "signupwidget.h"
#include "ui_signupwidget.h"

signUpWidget::signUpWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signupWidget) {
    ui->setupUi(this);
}

signUpWidget::~signUpWidget() {
    delete ui;
}

void signUpWidget::on_okBtn_clicked() {
    QString usr = ui->usrLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString pwd = ui->pwdLineEdit->text();
    QRadioButton* btn = qobject_cast<QRadioButton*>(ui->buttonGroup->checkedButton());
    if (btn == nullptr) {
        QMessageBox::warning(this, tr("提示"), tr("请选择你的角色"), QMessageBox::Ok);
    }
    else {
        QString roleName = btn->objectName();
        bool role;
        if (!QString::compare(roleName, "playerBtn")) {
            role = PLAYER;
        }
        else {
            role = QUESTIONER;
        }
        if (usr.length() < 6 || usr.length() > 20) {
            QMessageBox::warning(this, tr("提示"), tr("用户名必须为 6~20 个字符"), QMessageBox::Ok);
            ui->usrLineEdit->setFocus();
        }
        else if (name.length() < 6 || name.length() > 20) {
            QMessageBox::warning(this, tr("提示"), tr("昵称必须为 6~20 个字符"), QMessageBox::Ok);
            ui->nameLineEdit->setFocus();
        }
        else if (pwd.length() < 6 || pwd.length() > 20) {
            QMessageBox::warning(this, tr("提示"), tr("密码必须为 6~20 个字符"), QMessageBox::Ok);
            ui->pwdLineEdit->setFocus();
        }
        else {
             userdbManager man;
             if (man.queryUserdb(usr)) {
                QMessageBox::warning(this, tr("提示"), tr("该用户名已被使用"), QMessageBox::Ok);
                ui->usrLineEdit->setFocus();
            }
            else {
                man.addUserdb(usr, name, pwd, role);
                QMessageBox::warning(this, tr(""), tr("注册成功！"), QMessageBox::Ok);
                emit toSignIn();
            }
        }
    }
}

void signUpWidget::on_returnBtn_clicked() {
    emit toSignIn();
}

void signUpWidget::init() {
    ui->usrLineEdit->clear();
    ui->pwdLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->usrLineEdit->setFocus();
    ui->playerBtn->setChecked(false);
    ui->questionerBtn->setChecked(false);
}
