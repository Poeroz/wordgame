/**
 * @file playerpassedwidget.h
 *
 * @brief 闯关成功的界面。
 * @author 房庆凯 - 2017211131
 */

#ifndef PLAYERPASSEDWIDGET_H
#define PLAYERPASSEDWIDGET_H

#include <QWidget>

namespace Ui {
class playerPassedWidget;
}

/**
 * @brief 闯关成功的界面。
 */
class playerPassedWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit playerPassedWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~playerPassedWidget();

signals:
    /**
     * @brief 从闯关成功界面进入游戏界面的信号。
     */
    void passedToGaming();

    /**
     * @brief 从闯关成功界面切换到选择关卡界面的信号。
     */
    void passedToChLevel();

private slots:
    /**
     * @brief 当按下下一关按钮的操作。
     */
    void on_nextBtn_clicked();

    /**
     * @brief 当按下返回按钮的操作。
     */
    void on_returnBtn_clicked();

private:
    Ui::playerPassedWidget *ui;
};

#endif // PLAYERPASSEDWIDGET_H
