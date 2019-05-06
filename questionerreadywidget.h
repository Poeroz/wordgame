/**
 * @file questionerreadywidget.h
 *
 * @brief 出题者准备界面。
 * @author 房庆凯 - 2017211131
 */

#ifndef QUESTIONERREADYWIDGET_H
#define QUESTIONERREADYWIDGET_H

#include <QWidget>
#include "questioner.h"

namespace Ui {
class questionerReadyWidget;
}

/**
 * @brief 出题者准备界面。
 */
class questionerReadyWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit questionerReadyWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~questionerReadyWidget();

    /**
     * @brief 对窗口进行初始化，显示当前用户的信息。
     * @param user 当前出题者的信息。
     */
    void init(questioner user);

signals:
    /**
     * @brief 从准备界面切换到显示所有用户信息的界面。
     */
    void readyToAllUser();

    /**
     * @brief 从准备界面进入游戏界面。
     */
    void readyToGaming();

private slots:
    /**
     * @brief 点击显示所有用户的信息。
     */
    void on_allUserBtn_2_clicked();

    /**
     * @brief 点击开始游戏。
     */
    void on_startBtn_2_clicked();

private:
    Ui::questionerReadyWidget *ui;
};

#endif // QUESTIONERREADYWIDGET_H
