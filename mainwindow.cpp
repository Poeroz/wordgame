#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    initDatabase();
}

MainWindow::~MainWindow() {
    delete ui;
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
                QMessageBox::information(this, tr("Successful"), tr("Sign in successfully!"), QMessageBox::Ok);
            }
            else { /* not found */
                QMessageBox::warning(this, tr("Warning"), tr("Wrong username or password!"), QMessageBox::Ok);
                ui->pwdLineEdit->clear(); /* clear the password line edit */
                ui->pwdLineEdit->setFocus(); /* set the focus on password line edit to input password again */
            }
        }
    }
}

void MainWindow::receiveData(QString regUsr, QString regName, QString regPwd, bool regRole) {
    QSqlQuery query(userinfo);
    /* insert new user into database userinfo */
    QString str = "insert into user values(:usr, :name, :pwd, :role, 0, 0, 0, 0)";
    query.prepare(str);
    query.bindValue(":usr", regUsr);
    query.bindValue(":name", regName);
    query.bindValue(":pwd", regPwd);
    query.bindValue(":role", regRole);
    if (!query.exec()) {
        qDebug() << "Error here:" << query.lastError();
    }
    else {
        printDatabase();
    }
}

void MainWindow::on_signUpBtn_clicked() {
    signUpDialog *dlg = new signUpDialog;
    connect(dlg, SIGNAL(sendData(QString, QString, QString, bool)),
            this, SLOT(receiveData(QString, QString, QString, bool)));
    dlg->exec();
}

void MainWindow::on_quitBtn_clicked() {
    this->close();
}
