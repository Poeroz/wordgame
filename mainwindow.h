/**
 * @file mainwindow.h
 *
 * @brief 登录窗口。
 * @author 房庆凯 - 2017211131
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "signupdialog.h"
#include "player.h"
#include "questioner.h"
#include "playerwindow.h"
#include "questionerwindow.h"
#include "userdbmanager.h"

namespace Ui {
class MainWindow;
}

/**
 * @brief 登录窗口。
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
     * @brief 点击登录按钮后的操作。
     */
    void on_signInBtn_clicked();

    /**
     * @brief 点击注册按钮后的操作。
     */
    void on_signUpBtn_clicked();

    /**
     * @brief 点击退出按钮后的操作。
     */
    void on_quitBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
