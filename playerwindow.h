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
#include "chooselevelwidget.h"
#include "playerpassedwidget.h"
#include "playerfailedwidget.h"

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

signals:
    /**
     * @brief 更新闯关者信息。
     * @param newPlayer 更新后的闯关者。
     */
    void updatePlayerInfo(const player &newPlayer);

private slots:
    /**
     * @brief 从准备界面切换到显示所有用户的界面。
     */
    void switchReadyToAllUser();

    /**
     * @brief 从准备界面进入到游戏界面。
     */
    void switchReadyToChLevel();

    /**
     * @brief 从显示所有用户的界面切换回准备界面。
     */
    void switchAllUserToReady();

    /**
     * @brief 从游戏界面回到准备界面。
     */
    void switchChLevelToReady();

    /**
     * @brief 从选择关卡界面进入到游戏界面。
     */
    void switchChLevelToGaming(int levelId);

    /**
     * @brief 从游戏界面回到菜单界面。
     */
    void switchGamingToChLevel();

    /**
     * @brief 从游戏界面切换到闯关失败界面。
     */
    void switchGamingToFailed();

    /**
     * @brief 从游戏界面切换到闯关成功界面。
     */
    void switchGamingToPassed(int currentLevel, int plusExp);

    /**
     * @brief 从闯关成功界面切换到游戏界面。
     */
    void switchPassedToGaming();

    /**
     * @brief 从闯关成功界面切换到菜单界面。
     */
    void switchPassedToChLevel();

    /**
     * @brief 从闯关失败界面切换到游戏界面。
     */
    void switchFailedToGaming();

    /**
     * @brief 从闯关失败界面切换到菜单界面。
     */
    void switchFailedToChLevel();

    /**
     * @brief 关闭窗口。
     */
    void closeWindow();

private:
    Ui::playerWindow *ui;
    playerReadyWidget *ready;                   /**< 准备界面。 */
    playerGamingWidget *gaming;                 /**< 游戏界面。 */
    allUserWidget *allUser;                     /**< 显示所有用户信息的界面。 */
    chooseLevelWidget *chLevel;                 /**< 选择关卡的界面。 */
    playerPassedWidget *passed;                 /**< 闯关成功的界面。 */
    playerFailedWidget *failed;                 /**< 闯关失败的界面。 */
    player *currentPlayer;                      /**< 当前闯关者。 */
};

#endif // PLAYERWINDOW_H
