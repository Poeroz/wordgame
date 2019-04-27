/**
 * @file alluserwidget.h
 *
 * @brief 显示所有用户信息的窗口。
 * @author 房庆凯 - 2017211131
 */

#ifndef ALLUSERWIDGET_H
#define ALLUSERWIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include <QAbstractItemView>
#include "userdb.h"
#include "playerfilterdialog.h"
#include "questionerfilterdialog.h"

namespace Ui {
class allUserWidget;
}

/**
 * @brief 显示所有用户信息的窗口。
 */
class allUserWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit allUserWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~allUserWidget();

private slots:
    /**
     * @brief 将表格按某一列排序。
     * @param col 列号。
     */
    void sortByColumn(int col);

    /**
     * @brief 当选中闯关者按钮时，显示所有闯关者信息。
     */
    void on_playerBtn_clicked();

    /**
     * @brief 当选中出题者按钮时，显示所有出题者信息。
     */
    void on_questionerBtn_clicked();

    /**
     * @brief 接收闯关者筛选条件。
     * @param str 闯关者筛选条件。
     */
    void playerReceiveData(QString str);

    /**
     * @brief 接收出题者筛选条件。
     * @param str 出题者筛选条件。
     */
    void questionerReceiveData(QString str);

    /**
     * @brief 点击查询按钮后的操作。
     */
    void on_filterBtn_clicked();

    /**
     * @brief 点击查看全部按钮后的操作。
     */
    void on_seeAllBtn_clicked();

private:
    Ui::allUserWidget *ui;

    /**
     * @brief 显示所有闯关者信息。
     * @param str 闯关者筛选条件。
     */
    void showPlayerTable(QString str);

    /**
     * @brief 显示所有出题者信息。
     * @param str 出题者筛选条件。
     */
    void showQuestionerTable(QString str);
};

#endif // ALLUSERWIDGET_H
