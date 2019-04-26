#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    initUserdb();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_signInBtn_clicked() {
    QString usr = ui->usrLineEdit->text();                  /* 用户名 */
    QString pwd = ui->pwdLineEdit->text();                  /* 密码 */
    if (usr == "") {                                        /* 用户名为空 */
        QMessageBox::warning(this, tr("提示"), tr("用户名不能为空"), QMessageBox::Ok);
    }
    else if (pwd == "") {                                   /* 密码为空 */
        QMessageBox::warning(this, tr("提示"), tr("密码不能为空"), QMessageBox::Ok);
    }
    else {
        QSqlDatabase userdb;
        userdb = QSqlDatabase::database("userConnect");                         /* 建立连接 */
        userdb.setDatabaseName("user.db");                                      /* 数据库名称为 user.db */
        if (!userdb.open()) {
            qDebug() << "not open!";
        }
        else {
            QSqlQuery query(userdb);
            QString str = QString("select * from user where username = :usr and password = :pwd");
            query.prepare(str);
            query.bindValue(":usr", usr);
            query.bindValue(":pwd", pwd);
            if (!query.exec()) {
                qDebug() << "query error";
            }
            else {
                if (query.next()) {                             /* 在数据库中找到该账户 */
                    /* QMessageBox::information(this, tr("Successful"), tr("Sign in successfully!"), QMessageBox::Ok); */
                    user base = user(query.value(USERNAME).toString(),
                                     query.value(NICKNAME).toString(),
                                     query.value(PASSWORD).toString(),
                                     query.value(GRADE).toInt());
                    if (query.value(ROLE) == PLAYER) {
                        player newUser = player(base,
                                                query.value(LEVELCNT).toInt(),
                                                query.value(EXPERIENCE).toInt());
                        playerWindow *newWindow = new playerWindow;
                        newWindow->init(newUser);
                        this->hide();                           /* 隐藏当前窗口 */
                        newWindow->show();                      /* 显示闯关者游戏窗口 */
                    }
                    else {
                        questioner nowUser = questioner(base, query.value(QUESTIONCNT).toInt());
                        /**
                         * @todo 出题者窗口
                         */
                    }
                }
                else {                                          /* 未找到该账户的记录 */
                    QMessageBox::warning(this, tr("提示"), tr("用户名或密码错误"), QMessageBox::Ok);
                    ui->pwdLineEdit->clear();                   /* 清空密码栏 */
                    ui->pwdLineEdit->setFocus();                /* 设置焦点，重新输入密码 */
                }         
            }

        }
    }
}

void MainWindow::receiveData(QString regUsr, QString regName, QString regPwd, bool regRole) {
    QSqlDatabase userdb;
    userdb = QSqlDatabase::database("userConnect");                         /* 建立连接 */
    userdb.setDatabaseName("user.db");                                      /* 数据库名称为 user.db */
    if (!userdb.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(userdb);
        /* 向数据库中插入新用户的信息 */
        QString str = "insert into user values(:usr, :name, :pwd, :role, 0, 0, 0, 0)";
        query.prepare(str);
        query.bindValue(":usr", regUsr);
        query.bindValue(":name", regName);
        query.bindValue(":pwd", regPwd);
        query.bindValue(":role", regRole);
        if (!query.exec()) {
            qDebug() << "Error here:" << query.lastError();
        }
    }

}

void MainWindow::on_signUpBtn_clicked() {
    signUpDialog *dlg = new signUpDialog;
    connect(dlg, SIGNAL(sendData(QString, QString, QString, bool)),
            this, SLOT(receiveData(QString, QString, QString, bool)));
    dlg->exec();                                            /* 打开注册框 */
}

void MainWindow::on_quitBtn_clicked() {
    this->close();
}
