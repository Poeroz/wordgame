/**
 * @file chooselevelwidget.h
 *
 * @brief 游戏菜单（选择关卡）界面。
 * @author 房庆凯 - 2017211131
 */

#ifndef CHOOSELEVELWIDGET_H
#define CHOOSELEVELWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>

namespace Ui {
class chooseLevelWidget;
}

/**
 * @brief 自定义按钮类，添加了编号属性。
 */
class CustomizedButton : public QPushButton {
    Q_OBJECT
public:
    /**
     * @brief 构造函数。
     */
    CustomizedButton();

    /**
     * @brief 获取按钮编号。
     * @return 按钮编号。
     */
    int getId();

    /**
     * @brief setId 设置按钮编号。
     * @param _id 按钮编号。
     */
    void setId(int _id);

private:
    int id;                                 /**< 按钮编号。 */
};

class chooseLevelWidget : public QWidget {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit chooseLevelWidget(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~chooseLevelWidget();

private:
    QVector<CustomizedButton*> btnlst;      /**< 按钮组。 */
    Ui::chooseLevelWidget *ui;

signals:
    /**
     * @brief 从菜单界面进入游戏界面的信号。
     * @param levelId 选择的关卡。
     */
    void chLevelToGaming(int levelId);

    /**
     * @brief 从菜单界面回到准备界面的信号。
     */
    void chLevelToReady();

private slots:
    /**
     * @brief 获得所点击按钮的编号。
     */
    void getBtnId();

    /**
     * @brief 当按下返回按钮的操作。
     */
    void on_pushButton_clicked();
};

#endif // CHOOSELEVELWIDGET_H
