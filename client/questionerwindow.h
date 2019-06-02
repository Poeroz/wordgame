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
#include "questionerreadywidget.h"
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

signals:
    /**
     * @brief 更新出题者信息的信号。
     * @param newQuestioner 当前出题者。
     */
    void updateQuestionerInfo(const questioner &newQuestioner);

private slots:
    /**
     * @brief 从准备界面切换到显示所有用户的界面。
     */
    void switchReadyToAllUser();

    /**
     * @brief 从准备界面进入到游戏界面。
     */
    void switchReadyToGaming();

    /**
     * @brief 从显示所有用户的界面切换回准备界面。
     */
    void switchAllUserToReady();

    /**
     * @brief 从游戏界面回到准备界面。
     */
    void switchGamingToReady();

    /**
     * @brief 更新出题者信息。
     */
    void updateQuestioner();

    /**
     * @brief 关闭出题者窗口。
     */
    void closeWindow();

private:
    Ui::questionerWindow *ui;
    questionerReadyWidget *ready;                   /**< 准备界面。 */
    questionerGamingWidget *gaming;                 /**< 游戏界面。 */
    allUserWidget *allUser;                         /**< 显示所有用户信息的界面。 */
    questioner *currentQuestioner;                  /**< 当前出题者。 */
};

#endif // QUESTIONERWINDOW_H
