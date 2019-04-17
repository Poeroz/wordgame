#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    userinfo = QSqlDatabase::addDatabase("QSQLITE", "connection_userinfo");
    userinfo.setDatabaseName("userinfo.db");
    if (!userinfo.open()) {
        qDebug() << "not open!";
    }
    QSqlQuery query(userinfo);
    query.exec("create table user (username varchar(20) primary key, password varchar(20))");
    query.exec("insert into user values('Poeroz', '123456')");
    query.exec("insert into user values('zhengrchan', '12345')");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_signInBtn_clicked()
{
    QString usr = ui->usrLineEdit->text();
    QString pwd = ui->pwdLineEdit->text();
    if (usr == "") {
        QMessageBox::warning(this, tr("Warning"), tr("Username can not be empty!"), QMessageBox::Ok);
    }
    else if (pwd == "") {
        QMessageBox::warning(this, tr("Warning"), tr("Password can not be empty!"), QMessageBox::Ok);
    }
    else {
        QString str = QString("select * from user where username = :usr and password = :pwd");
        QSqlQuery query(userinfo);
        query.prepare(str);
        query.bindValue(":usr", usr);
        query.bindValue(":pwd", pwd);
        if (!query.exec()) {
            qDebug() << "query error";
        }
        else {
            if (query.next()) {
                QMessageBox::information(this, tr("Successful"), tr("Log in successfully!"), QMessageBox::Ok);
            }
            else {
                QMessageBox::warning(this, tr("Warning"), tr("Wrong username or password!"), QMessageBox::Ok);
                ui->pwdLineEdit->clear();
                ui->pwdLineEdit->setFocus();
            }
        }
    }
}
