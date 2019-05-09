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

    /* 使用正则表达式约束 */
    ui->usrLineEdit->setValidator(new QRegExpValidator(QRegExp("^[A-Za-z0-9]{1,10}$"), this));
    ui->nameLineEdit->setValidator(new QRegExpValidator(QRegExp("^[A-Za-z0-9\u4e00-\u9fa5]{1,10}$"), this));
    ui->pwdLineEdit->setValidator(new QRegExpValidator(QRegExp("^.{1,10}$"), this));
    ui->pwdLineEdit_2->setValidator(new QRegExpValidator(QRegExp("^.{1,10}$"), this));
}

signUpWidget::~signUpWidget() {
    delete ui;
}

void signUpWidget::on_okBtn_clicked() {
    QString usr = ui->usrLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString pwd = ui->pwdLineEdit->text();
    QString pwd2 = ui->pwdLineEdit_2->text();
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
        if (usr.length() < 3) {
            QMessageBox::warning(this, tr("提示"), tr("用户名长度必须在 3 到 10 之间"), QMessageBox::Ok);
            ui->usrLineEdit->setFocus();
        }
        else if (name.length() < 3) {
            QMessageBox::warning(this, tr("提示"), tr("昵称长度必须在 3 到 10 之间"), QMessageBox::Ok);
            ui->nameLineEdit->setFocus();
        }
        else if (pwd.length() < 3) {
            QMessageBox::warning(this, tr("提示"), tr("密码长度必须在 3 到 10 之间"), QMessageBox::Ok);
            ui->pwdLineEdit->setFocus();
        }
        else if (pwd != pwd2) {
            QMessageBox::warning(this, tr("提示"), tr("两次密码输入不一致"), QMessageBox::Ok);
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
    ui->pwdLineEdit_2->clear();
    ui->usrLineEdit->setFocus();
    ui->buttonGroup->setExclusive(false);
    ui->playerBtn->setChecked(false);
    ui->questionerBtn->setChecked(false);
    ui->buttonGroup->setExclusive(true);
}
