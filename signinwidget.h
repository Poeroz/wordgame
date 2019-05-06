/**
 * @file signinwidget.h
 *
 * @brief 登录窗口。
 * @author 房庆凯 - 2017211131
 */

#ifndef SIGNINWIDGET_H
#define SIGNINWIDGET_H

#include <QWidget>
#include "player.h"
#include "questioner.h"
#include "playerwindow.h"
#include "questionerwindow.h"
#include "userdbmanager.h"

namespace Ui {
class signInWidget;
}

/**
 * @brief 登录窗口。
 */
class signInWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit signInWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~signInWidget();

    /**
     * @brief 初始化。
     */
    void init();

signals:
    /**
     * @brief 切换到注册窗口的信号。
     */
    void toSignUp();

    /**
     * @brief 关闭窗口的信号。
     */
    void closeWindow();

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
    void on_exitButton_clicked();

private:
    Ui::signInWidget *ui;
};

#endif // SIGNINWIDGET_H
