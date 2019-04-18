#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>

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
    void sendData(QString, QString); /* send data to mainwindow */

private slots:
    void on_buttonBox_accepted(); /* slots when clicked OK */
};

#endif // SIGNUPDIALOG_H
