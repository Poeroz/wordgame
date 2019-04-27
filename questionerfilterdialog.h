/**
 * @file playerfilterdialog.h
 *
 * @brief 出题者条件筛选对话框。
 * @author 房庆凯 - 2017211131
 */

#ifndef QUESTIONERFILTERDIALOG_H
#define QUESTIONERFILTERDIALOG_H

#include <QDialog>
#include "userdb.h"

namespace Ui {
class questionerFilterDialog;
}

/**
 * @brief 出题者条件筛选对话框。
 */
class questionerFilterDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief 构造函数。
     */
    explicit questionerFilterDialog(QWidget *parent = nullptr);

    /**
     * @brief 析构函数。
     */
    ~questionerFilterDialog();

private slots:
    /**
     * @brief 按下 OK 键后的操作。
     */
    void on_okBtn_clicked();

signals:
    /**
     * @brief 发送出题者筛选条件给父窗口。
     */
    void questionerSendData(QString);

private:
    Ui::questionerFilterDialog *ui;
};

#endif // QUESTIONERFILTERDIALOG_H
