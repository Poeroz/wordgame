/**
 * @file playergamingwidget.h
 *
 * @brief 闯关者游戏界面。
 * @author 房庆凯 - 2017211131
 */

#ifndef PLAYERGAMINGWIDGET_H
#define PLAYERGAMINGWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QProgressBar>
#include <QMessageBox>
#include <QPair>
#include "worddbmanager.h"

namespace Ui {
class playerGamingWidget;
}

const int TOTAL = 5;                                    /**< 每一关卡的总轮数。 */

/**
 * @brief 闯关者游戏界面类。
 */
class playerGamingWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit playerGamingWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~playerGamingWidget();

    /**
     * @brief 初始化，默认值为 -1，表示不对关卡进行更改。
     */
    void init(int levelId = -1);

    /**
     * @brief 停止游戏。
     */
    void stop();

private slots:
    /**
     * @brief 根据当前剩余时间更新进度条的进度。
     */
    void updateProgressBar();

    /**
     * @brief 按下 OK 按钮时的操作。
     */
    void on_okBtn_clicked();

    /**
     * @brief 按下退出游戏按钮后的操作。
     */
    void on_exitBtn_clicked();

signals:
    /**
     * @brief 从游戏界面回到菜单界面的信号。
     */
    void gamingToChLevel();

    /**
     * @brief 从游戏界面切换到闯关失败界面的信号。
     */
    void gamingToFailed();

    /**
     * @brief 从游戏界面切换到闯关成功界面的信号。
     */
    void gamingToPassed();

private:
    Ui::playerGamingWidget *ui;

    /**
     * @brief 显示一个新单词。
     */
    void showNewWord();

    int restTime;                                       /**< 本轮剩余时间。 */
    int nowLevel;                                       /**< 当前关卡数。 */
    int passCnt;                                        /**< 本关当前轮数。 */
    QTimer *myTimer;                                    /**< 倒计时用定时器。 */
};

#endif // PLAYERGAMINGWIDGET_H

