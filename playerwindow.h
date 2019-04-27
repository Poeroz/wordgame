/**
 * @file playerwindow.h
 *
 * @brief 闯关者游戏主窗口。
 * @author 房庆凯 - 2017211131
 */

#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QMainWindow>
#include "player.h"
#include "userdb.h"
#include "alluserwidget.h"

namespace Ui {
class playerWindow;
}

/**
 * @brief 闯关者游戏主窗口。
 */
class playerWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit playerWindow(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~playerWindow();

    /**
     * @brief 对窗口进行初始化。
     * @param user 当前闯关者的信息。
     */
    void init(player user);

private slots:
    /**
     * @brief 点击显示所有用户的信息。
     */
    void on_allUserBtn_clicked();

private:
    Ui::playerWindow *ui;
};

#endif // PLAYERWINDOW_H
