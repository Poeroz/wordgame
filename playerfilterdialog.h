/**
 * @file playerfilterdialog.h
 *
 * @brief 闯关者条件筛选对话框。
 * @author 房庆凯 - 2017211131
 */

#ifndef PLAYERFILTERDIALOG_H
#define PLAYERFILTERDIALOG_H

#include <QDialog>
#include "userdbmanager.h"

namespace Ui {
class playerFilterDialog;
}

/**
 * @brief 闯关者条件筛选对话框。
 */
class playerFilterDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit playerFilterDialog(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~playerFilterDialog();

private slots:
    /**
     * @brief 按下 OK 键后的操作。
     */
    void on_okBtn_clicked();

signals:
    /**
     * @brief 发送闯关者筛选条件给父窗口。
     */
    void playerSendData(QString);

private:
    Ui::playerFilterDialog *ui;
};

#endif // PLAYERFILTERDIALOG_H
