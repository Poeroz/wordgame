/**
 * @file signupwidget.h
 *
 * @brief 注册窗口。
 * @author 房庆凯 - 2017211131
 */

#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "userdbmanager.h"
#include <QRegExpValidator>

namespace Ui {
class signupWidget;
}

/**
 * @brief 注册窗口。
 */
class signUpWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit signUpWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~signUpWidget();

    /**
     * @brief 初始化。
     */
    void init();

signals:
    /**
     * @brief 切换到登录窗口的信号。
     */
    void toSignIn();

private slots:
    /**
     * @brief 点击立即注册按钮时的操作。
     */
    void on_okBtn_clicked();

    /**
     * @brief 点击返回按钮时的操作。
     */
    void on_returnBtn_clicked();

private:
    Ui::signupWidget *ui;
};

#endif // SIGNUPWIDGET_H
