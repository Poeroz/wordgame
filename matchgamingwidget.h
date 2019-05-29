/**
 * @file matchgamingwidget.h
 *
 * @brief 匹配模式游戏界面。
 * @author 房庆凯 - 2017211131
 */

#ifndef MATCHGAMINGWIDGET_H
#define MATCHGAMINGWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <QProgressBar>
#include <QMessageBox>
#include <QPair>
#include <QtMath>
#include <QRegExpValidator>

namespace Ui {
class matchGamingWidget;
}

/**
 * @brief 匹配模式游戏界面。
 */
class matchGamingWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     * @param 父窗口。
     */
    explicit matchGamingWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~matchGamingWidget();

    /**
     * @brief 初始化界面。
     * @param 显示的文本。
     */
    void init(QString text);

    /**
     * @brief 结束界面。
     * @param 显示的文本。
     */
    void end(QString text);

    /**
     * @brief 开始游戏。
     * @param rhs 单词列表。
     */
    void start(const QVector<QString> &rhs);

signals:
    /**
     * @brief 游戏结束的信号。
     * @param totalTime 游戏花费的总时间。
     */
    void endGame(int totalTime);

    /**
     * @brief 取消匹配的信号。
     */
    void cancelMatch();

private slots:
    /**
     * @brief 更新进度条。
     */
    void updateProgressBar();

    /**
     * @brief 按下 OK 按钮的操作。
     */
    void on_okBtn_clicked();

    /**
     * @brief 按下取消匹配按钮的操作。
     */
    void on_cancelBtn_clicked();

private:
    Ui::matchGamingWidget *ui;

    /**
     * @brief 显示一个新单词。
     */
    void showNewWord();

    QVector<QString> wordlist;                          /**< 单词列表。 */
    int restTime;                                       /**< 本轮剩余时间。 */
    int nowLevel;                                       /**< 当前关卡数。 */
    int passCnt;                                        /**< 本关当前轮数。 */
    QElapsedTimer *totalTime;                           /**< 本关花费的总时间。 */
    QTimer *myTimer;                                    /**< 倒计时用定时器。 */
};

#endif // MATCHGAMINGWIDGET_H
