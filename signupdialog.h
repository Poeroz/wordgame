/**
 * @file signupdialog.h
 *
 * @brief 注册对话框。
 * @author 房庆凯 - 2017211131
 */

#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "userdbmanager.h"

namespace Ui {
class signUpDialog;
}

/**
 * @brief 注册对话框。
 */
class signUpDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit signUpDialog(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~signUpDialog();

private:
    Ui::signUpDialog *ui;

private slots:
    /**
     * @brief 点击 OK 时的操作。
     */
    void on_okBtn_clicked();
};

#endif // SIGNUPDIALOG_H
