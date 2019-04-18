#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "base.h"
#include "signupdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); /* constructor */

    ~MainWindow(); /* destructor */

private slots:
    void on_signInBtn_clicked(); /* slots when click the sign in button */

    void on_signUpBtn_clicked(); /* slots when click the sign up button */

    void receiveData(QString regUsr, QString regName, QString regPwd, bool regRole); /* reveive username and password from the sign up dialog */

    void on_quitBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
