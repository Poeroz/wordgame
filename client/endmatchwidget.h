/**
 * @file endmatchwidget.h
 *
 * @brief 匹配模式结束后的界面。
 * @author 房庆凯 - 2017211131
 */

#ifndef ENDMATCHWIDGET_H
#define ENDMATCHWIDGET_H

#include <QWidget>

namespace Ui {
class endMatchWidget;
}

/**
 * @brief 匹配模式结束后的界面。
 */
class endMatchWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit endMatchWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~endMatchWidget();

    /**
     * @brief 初始化函数。
     * @param winState 游戏结果（-1 表示输，0 表示平局，1 表示胜利）。
     * @param getExp 获得的经验值。
     */
    void init(bool winState, int getExp);

signals:
    /**
     * @brief 回到准备界面的信号。
     */
    void endToReady();

private slots:
    /**
     * @brief 按下返回主界面按钮的操作。
     */
    void on_backBtn_clicked();

private:
    Ui::endMatchWidget *ui;
};

#endif // ENDMATCHWIDGET_H
