#ifndef QUESTIONERFILTERDIALOG_H
#define QUESTIONERFILTERDIALOG_H

#include <QDialog>

namespace Ui {
class questionerFilterDialog;
}

class questionerFilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit questionerFilterDialog(QWidget *parent = nullptr);
    ~questionerFilterDialog();

private:
    Ui::questionerFilterDialog *ui;
};

#endif // QUESTIONERFILTERDIALOG_H
