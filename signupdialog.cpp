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
        QMessageBox::warning(this, tr("提示"), tr("请选择你的角色"), QMessageBox::Ok);
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
            QSqlDatabase userdb;
            userdb = QSqlDatabase::database("userConnect");                         /* 建立连接 */
            userdb.setDatabaseName("user.db");                                      /* 数据库名称为 user.db */
            if (!userdb.open()) {
                qDebug() << "not open!";
            }
            else {
                QSqlQuery query(userdb);
                QString str = "select * from user where username = :usr";
                query.prepare(str);
                query.bindValue(":usr", usr);
                if (!query.exec()) {
                    qDebug() << "query error";
                }
                else {
                    if (query.next()) {
                        QMessageBox::warning(this, tr("提示"), tr("该用户名已被使用"), QMessageBox::Ok);
                        ui->usrLineEdit->setFocus();
                    }
                    else {
                        emit sendData(usr, name, pwd, role);
                        QMessageBox::warning(this, tr(""), tr("注册成功！"), QMessageBox::Ok);
                        this->accept();
                    }
                }
            }
        }
    }
}

