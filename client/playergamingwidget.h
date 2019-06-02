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
#include <QElapsedTimer>
#include <QProgressBar>
#include <QMessageBox>
#include <QPair>
#include <QtMath>
#include <QRegExpValidator>
#include "worddbmanager.h"

namespace Ui {
class playerGamingWidget;
}

const int MIN_LENGTH[17] = {0, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};       /**< 每一关的最小单词长度。 */
const int MAX_LENGTH[17] = {0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};   /**< 每一关的最大单词长度。 */
const int TOTAL_ROUND[17] = {0, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8};           /**< 每一关的总轮数。 */
const int TOTAL_TIME[17] = {0, 6, 6, 6, 6, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3};            /**< 每一轮的总时间。 */

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
     * @param currentLevel 当前通过关卡数。
     */
    void gamingToPassed(int currentLevel, int plusExp);

private:
    Ui::playerGamingWidget *ui;

    /**
     * @brief 显示一个新单词。
     */
    void showNewWord();

    int restTime;                                       /**< 本轮剩余时间。 */
    int nowLevel;                                       /**< 当前关卡数。 */
    int passCnt;                                        /**< 本关当前轮数。 */
    int totalLength;                                    /**< 本关单词总长度。 */
    QElapsedTimer *totalTime;                           /**< 本关花费的总时间。 */
    QTimer *myTimer;                                    /**< 倒计时用定时器。 */
};

#endif // PLAYERGAMINGWIDGET_H

