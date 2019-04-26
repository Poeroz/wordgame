/**
 * @file mainwindow.h
 *
 * @brief 登录窗口
 * @author 房庆凯 - 2017211131
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "userdb.h"
#include "signupdialog.h"
#include "player.h"
#include "questioner.h"
#include "playerwindow.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief 登录窗口
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief 析构函数
     */
    ~MainWindow();

private slots:
    /**
     * @brief 点击登录按钮后的操作
     */
    void on_signInBtn_clicked();

    /**
     * @brief 点击注册按钮后的操作
     */
    void on_signUpBtn_clicked();

    /**
     * @brief 从注册对话框接收新用户的信息
     * @param regUsr 用户名
     * @param regName 昵称
     * @param regPwd 密码
     * @param regRole 角色
     */
    void receiveData(QString regUsr, QString regName, QString regPwd, bool regRole);

    /**
     * @brief 点击退出按钮后的操作
     */
    void on_quitBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
