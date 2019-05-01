/**
 * @file questionergamingwidget.h
 *
 * @brief 出题者游戏中界面。
 * @author 房庆凯 - 2017211131
 */

#ifndef QUESTIONERGAMINGWIDGET_H
#define QUESTIONERGAMINGWIDGET_H

#include <QMessageBox>
#include <QWidget>
#include "worddbmanager.h"

namespace Ui {
class questionerGamingWidget;
}

/**
 * @brief 出题者游戏中界面类。
 */
class questionerGamingWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     * @param 父窗口。
     */
    explicit questionerGamingWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~questionerGamingWidget();

private slots:
    /**
     * @brief 按下 OK 按钮时的操作。
     */
    void on_okBtn_clicked();

    /**
     * @brief 按下结束游戏按钮时的操作。
     */
    void on_endgameBtn_clicked();

private:
    Ui::questionerGamingWidget *ui;
};

#endif // QUESTIONERGAMINGWIDGET_H
