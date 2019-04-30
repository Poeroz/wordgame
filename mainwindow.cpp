#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    userdbManager::initUserdb();
    worddbManager::initWorddb();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_signInBtn_clicked() {
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
            player newUser = man.getPlayer(usr, pwd);
            playerWindow *newWindow = new playerWindow;
            newWindow->init(newUser);
            this->hide();                                       /* 隐藏当前窗口 */
            newWindow->show();                                  /* 显示闯关者游戏窗口 */
        }
        else if (type == QUESTIONER) {
            questioner newUser = man.getQuestioner(usr, pwd);
            questionerWindow *newWindow = new questionerWindow;
            newWindow->init(newUser);
            this->hide();
            newWindow->show();
        }
        else {                                                      /* 未找到该账户的记录 */
            QMessageBox::warning(this, tr("提示"), tr("用户名或密码错误"), QMessageBox::Ok);
            ui->pwdLineEdit->clear();                               /* 清空密码栏 */
            ui->pwdLineEdit->setFocus();                            /* 设置焦点，重新输入密码 */
        }
    }
}

void MainWindow::on_signUpBtn_clicked() {
    signUpDialog *dlg = new signUpDialog;
    dlg->exec();                                                            /* 打开注册框 */
}

void MainWindow::on_quitBtn_clicked() {
    this->close();
}
