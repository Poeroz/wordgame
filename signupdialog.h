#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "base.h"

namespace Ui {
class signUpDialog;
}

class signUpDialog : public QDialog {
    Q_OBJECT

public:
    explicit signUpDialog(QWidget *parent = nullptr); /* construtor */

    ~signUpDialog(); /* destructor */

private:
    Ui::signUpDialog *ui;

signals:
    void sendData(QString, QString, QString, bool); /* send data to mainwindow */

private slots:
    void on_okBtn_clicked();
};

#endif // SIGNUPDIALOG_H
