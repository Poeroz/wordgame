/**
 * @file playerfailedwidget.h
 *
 * @brief 闯关失败的界面。
 * @author 房庆凯 - 2017211131
 */

#ifndef PLAYERFAILEDWIDGET_H
#define PLAYERFAILEDWIDGET_H

#include <QWidget>

namespace Ui {
class playerFailedWidget;
}

/**
 * @brief 闯关失败的界面类。
 */
class playerFailedWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit playerFailedWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~playerFailedWidget();

signals:
    /**
     * @brief 从闯关失败界面进入游戏界面的信号。
     */
    void failedToGaming();

    /**
     * @brief 从闯关失败界面切换到选择关卡界面的信号。
     */
    void failedToChLevel();

private slots:
    /**
     * @brief 当按下重新开始按钮的操作。
     */
    void on_retryBtn_clicked();

    /**
     * @brief 当按下返回按钮的操作。
     */
    void on_returnBtn_clicked();

private:
    Ui::playerFailedWidget *ui;
};

#endif // PLAYERFAILEDWIDGET_H
