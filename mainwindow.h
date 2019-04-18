#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); /* constructor */

    ~MainWindow(); /* destructor */

    void printDatabase(); /* print all records in the database user */

    void clearDatabase(); /* remove all records in the database user */

private slots:
    void on_signInBtn_clicked(); /* slots when click the sign in button */

    void on_signUpBtn_clicked(); /* slots when click the sign up button */

    void receiveData(QString regUsr, QString regPwd); /* reveive username and password from the sign up dialog */

private:
    Ui::MainWindow *ui;

    QSqlDatabase userinfo; /* database of userinfo */
};

#endif // MAINWINDOW_H
