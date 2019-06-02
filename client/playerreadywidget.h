/**
 * @file playerreadywidget.h
 *
 * @brief 闯关者准备界面。
 * @author 房庆凯 - 2017211131
 */

#ifndef PLAYERREADYWIDGET_H
#define PLAYERREADYWIDGET_H

#include <QWidget>
#include "player.h"
#include "tcpmanager.h"

namespace Ui {
class playerReadyWidget;
}

/**
 * @brief 闯关者准备界面。
 */
class playerReadyWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit playerReadyWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~playerReadyWidget();

    /**
     * @brief 初始化，显示当前用户的信息。
     * @param user 当前闯关者的信息。
     */
    void init(player user);

private slots:
    /**
     * @brief 点击显示所有用户的信息。
     */
    void on_allUserBtn_clicked();

    /**
     * @brief 点击开始游戏。
     */
    void on_startBtn_clicked();

    /**
     * @brief 更新闯关者信息。
     * @param 当前闯关者信息。
     */
    void refreshPlayer(const player &newPlayer);

    /**
     * @brief 按下退出游戏按钮的操作。
     */
    void on_exitBtn_clicked();

    void on_matchBtn_clicked();

signals:
    /**
     * @brief 从准备界面切换到显示所有用户的界面的信号。
     */
    void readyToAllUser();

    /**
     * @brief 从准备界面进入到选择关卡界面的信号。
     */
    void readyToChLevel();

    /**
     * @brief 退出游戏的信号。
     */
    void exitGame();

    /**
     * @brief 匹配信号。
     */
    void matchGame();

private:
    Ui::playerReadyWidget *ui;
};

#endif // PLAYERREADYWIDGET_H
