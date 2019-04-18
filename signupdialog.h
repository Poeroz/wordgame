#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>

namespace Ui {
class signUpDialog;
}

class signUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit signUpDialog(QWidget *parent = nullptr);
    ~signUpDialog();

private:
    Ui::signUpDialog *ui;

signals:
    void sendData(QString, QString);

private slots:
    void on_buttonBox_accepted();
};

#endif // SIGNUPDIALOG_H
