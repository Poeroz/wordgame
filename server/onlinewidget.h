/**
 * @file onlinewidget.h
 *
 * @brief 显示所有在线玩家。
 * @author 房庆凯 - 2017211131
 */

#ifndef ONLINEWIDGET_H
#define ONLINEWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTableWidget>

namespace Ui {
class onlineWidget;
}

/**
 * @brief 显示所有在线玩家。
 */
class onlineWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     * @param 父窗口。
     */
    explicit onlineWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~onlineWidget();

private slots:
    /**
     * @brief 更新表格。
     */
    void refreshTable(QVector<QString> userList);

private:
    Ui::onlineWidget *ui;
};

#endif // ONLINEWIDGET_H
