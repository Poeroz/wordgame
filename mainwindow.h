/**
 * @file mainwindow.h
 *
 * @brief 主窗口。
 * @author 房庆凯 - 2017211131
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "signupwidget.h"
#include "signinwidget.h"
#include "player.h"
#include "questioner.h"
#include "playerwindow.h"
#include "questionerwindow.h"
#include "userdbmanager.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief 主窗口。
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~MainWindow();

private slots:
    /**
     * @brief 由登录窗口切换到注册窗口。
     */
    void switchToSignUp();

    /**
     * @brief 由注册窗口切换到登录窗口。
     */
    void switchToSignIn();

    /**
     * @brief 退出程序。
     */
    void exitProgram();

private:
    Ui::MainWindow *ui;
    signUpWidget *signUp;               /**< 注册窗口。 */
    signInWidget *signIn;               /**< 登录窗口。 */
};

#endif // MAINWINDOW_H
