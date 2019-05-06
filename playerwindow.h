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
#include "userdbmanager.h"
#include "alluserwidget.h"
#include "playerreadywidget.h"
#include "playergamingwidget.h"

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
     * @brief 对窗口进行初始化，显示当前用户的信息。
     * @param user 当前闯关者的信息。
     */
    void init(player user);

private slots:
    /**
     * @brief 从准备界面切换到显示所有用户的界面。
     */
    void switchReadyToAllUser();

    /**
     * @brief 从准备界面进入到游戏界面。
     */
    void switchReadyToGaming();

    /**
     * @brief 从显示所有用户的界面切换回准备界面。
     */
    void switchAllUserToReady();

    /**
     * @brief 从游戏界面回到准备界面。
     */
    void switchGamingToReady();

private:
    Ui::playerWindow *ui;
    playerReadyWidget *ready;                   /**< 准备界面。 */
    playerGamingWidget *gaming;                 /**< 游戏界面。 */
    allUserWidget *allUser;                     /**< 显示所有用户信息的界面。 */
};

#endif // PLAYERWINDOW_H
