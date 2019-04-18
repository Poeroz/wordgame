#include "signupdialog.h"
#include "ui_signupdialog.h"

signUpDialog::signUpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signUpDialog) {
    ui->setupUi(this);
}

signUpDialog::~signUpDialog() {
    delete ui;
}

void signUpDialog::on_okBtn_clicked() {
    QString usr = ui->usrLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString pwd = ui->pwdLineEdit->text();
    QRadioButton* btn = qobject_cast<QRadioButton*>(ui->buttonGroup->checkedButton());
    if (btn == nullptr) {
        QMessageBox::warning(this, tr("Warning"), tr("You must choose your role"), QMessageBox::Ok);
    }
    else {
        QString roleName = btn->objectName();
        bool role;
        if(!QString::compare(roleName, "playerBtn")) {
            role = PLAYER;
        }
        else {
            role = QUESTIONER;
        }
        if (usr.length() < 6 || usr.length() > 20) {
            QMessageBox::warning(this, tr("Warning"), tr("Username should be 6~20 characters!"), QMessageBox::Ok);
            ui->usrLineEdit->setFocus();
        }
        else if (name.length() < 6 || name.length() > 20) {
            QMessageBox::warning(this, tr("Warning"), tr("Nickname should be 6~20 characters!"), QMessageBox::Ok);
            ui->nameLineEdit->setFocus();
        }
        else if (pwd.length() < 6 || pwd.length() > 20) {
            QMessageBox::warning(this, tr("Warning"), tr("Password should be 6~20 characters!"), QMessageBox::Ok);
            ui->pwdLineEdit->setFocus();
        }
        else {
            QSqlQuery query(userinfo);
            QString str = "select * from user where username = :usr";
            query.prepare(str);
            query.bindValue(":usr", usr);
            if (!query.exec()) {
                qDebug() << "query error";
            }
            else {
                if (query.next()) {
                    QMessageBox::warning(this, tr("Warning"), tr("Username has been used, please try another!"), QMessageBox::Ok);
                    ui->usrLineEdit->setFocus();
                }
                else {
                    emit sendData(usr, name, pwd, role);
                    QMessageBox::warning(this, tr("Successful"), tr("Sign up successfully!"), QMessageBox::Ok);
                    this->accept();
                }
            }
        }
    }
}

