/**
 * @file signinwidget.cpp
 *
 * @brief 登录窗口。
 * @author 房庆凯 - 2017211131
 */

#include "signinwidget.h"
#include "ui_signinwidget.h"

signInWidget::signInWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signInWidget) {
    ui->setupUi(this);
}

signInWidget::~signInWidget() {
    delete ui;
}

void signInWidget::on_signInBtn_clicked() {
    QString usr = ui->usrLineEdit->text();                                  /* 用户名 */
    QString pwd = ui->pwdLineEdit->text();                                  /* 密码 */
    if (usr == "") {                                                        /* 用户名为空 */
        QMessageBox::warning(this, tr("提示"), tr("用户名不能为空"), QMessageBox::Ok);
    }
    else if (pwd == "") {                                                   /* 密码为空 */
        QMessageBox::warning(this, tr("提示"), tr("密码不能为空"), QMessageBox::Ok);
    }
    else {
        userdbManager man;
        int type = man.checkUser(usr, pwd);
        if (type == PLAYER) {
            player newUser = man.getPlayer(usr);
            playerWindow *newWindow = new playerWindow;
            newWindow->init(newUser);
            emit closeWindow();                                             /* 隐藏当前窗口 */
            newWindow->show();                                              /* 显示闯关者游戏窗口 */
        }
        else if (type == QUESTIONER) {
            questioner newUser = man.getQuestioner(usr);
            questionerWindow *newWindow = new questionerWindow;
            newWindow->init(newUser);
            emit closeWindow();
            newWindow->show();
        }
        else {                                                              /* 未找到该账户的记录 */
            QMessageBox::warning(this, tr("提示"), tr("用户名或密码错误"), QMessageBox::Ok);
            ui->pwdLineEdit->clear();                                       /* 清空密码栏 */
            ui->pwdLineEdit->setFocus();                                    /* 设置焦点，重新输入密码 */
        }
    }
}

void signInWidget::on_signUpBtn_clicked() {
    emit toSignUp();
}

void signInWidget::on_exitButton_clicked() {
    emit closeWindow();
}

void signInWidget::init() {
    ui->usrLineEdit->clear();
    ui->pwdLineEdit->clear();
    ui->usrLineEdit->setFocus();
}
