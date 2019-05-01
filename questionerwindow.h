/**
 * @file questionerwindow.h
 *
 * @brief 出题者游戏主窗口。
 * @author 房庆凯 - 2017211131
 */

#ifndef QUESTIONERWINDOW_H
#define QUESTIONERWINDOW_H

#include <QMainWindow>
#include "questioner.h"
#include "userdbmanager.h"
#include "alluserwidget.h"
#include "questionergamingwidget.h"

namespace Ui {
class questionerWindow;
}

/**
 * @brief 出题者游戏主窗口。
 */
class questionerWindow : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit questionerWindow(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~questionerWindow();

    /**
     * @brief 对窗口进行初始化，显示当前用户的信息。
     * @param user 当前出题者的信息。
     */
    void init(questioner user);

private slots:
    /**
     * @brief 点击显示所有用户的信息。
     */
    void on_allUserBtn_clicked();

    /**
     * @brief 点击开始游戏。
     */
    void on_startBtn_clicked();

private:
    Ui::questionerWindow *ui;
};

#endif // QUESTIONERWINDOW_H
