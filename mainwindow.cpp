#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    else if (usr == tr("Poeroz") && pwd == tr("123456")) {
        QMessageBox::information(this, tr("Successful"), tr("Log in successfully!"), QMessageBox::Ok);
    }
    else {
        QMessageBox::warning(this, tr("Warning"), tr("Wrong username or password!"), QMessageBox::Ok);
        ui->pwdLineEdit->clear();
        ui->pwdLineEdit->setFocus();
    }
}
