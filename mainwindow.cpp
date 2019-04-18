#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signupdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    userinfo = QSqlDatabase::addDatabase("QSQLITE", "connection_userinfo"); /* add connection */
    userinfo.setDatabaseName("userinfo.db"); /* set database name as userinfo.db */
    if (!userinfo.open()) { /* open database userinfo */
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(userinfo);
        query.exec("create table user (username varchar(20) primary key, password varchar(20))"); /* create a table called user */
    }

    printDatabase(); /* debug */
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::printDatabase() {
    QSqlQuery query(userinfo);
    if (!query.exec("select * from user")) {
        qDebug() << "print error";
    }
    else {
        while (query.next()) {
            QString usr = query.value(0).toString();
            QString pwd = query.value(1).toString();
            qDebug() << usr << pwd;
        }
    }
}

void MainWindow::clearDatabase() {
    QSqlQuery query(userinfo);
    if (!query.exec("delete from user")) {
        qDebug() << "clear error";
    }
}

void MainWindow::on_signInBtn_clicked() {
    QString usr = ui->usrLineEdit->text(); /* get username from line edit */
    QString pwd = ui->pwdLineEdit->text(); /* get password from line edit */
    if (usr == "") { /* username is empty */
        QMessageBox::warning(this, tr("Warning"), tr("Username can not be empty!"), QMessageBox::Ok);
    }
    else if (pwd == "") { /* password is empty */
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
            if (query.next()) { /* find from database userinfo successfully */
                QMessageBox::information(this, tr("Successful"), tr("Log in successfully!"), QMessageBox::Ok);
            }
            else { /* not found */
                QMessageBox::warning(this, tr("Warning"), tr("Wrong username or password!"), QMessageBox::Ok);
                ui->pwdLineEdit->clear(); /* clear the password line edit */
                ui->pwdLineEdit->setFocus(); /* set the focus on password line edit to input password again */
            }
        }
    }
}

void MainWindow::receiveData(QString regUsr, QString regPwd) {
    QSqlQuery query(userinfo);
    QString str = "insert into user values(:usr, :pwd)"; /* insert new user into database userinfo */
    query.prepare(str);
    query.bindValue(":usr", regUsr);
    query.bindValue(":pwd", regPwd);
    if (!query.exec()) {
        qDebug() << "insert error";
    }
}

void MainWindow::on_signUpBtn_clicked() {
    signUpDialog *dlg = new signUpDialog;
    connect(dlg, SIGNAL(sendData(QString, QString)), this, SLOT(receiveData(QString, QString)));
    dlg->exec();
}
