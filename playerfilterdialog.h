#ifndef PLAYERFILTERDIALOG_H
#define PLAYERFILTERDIALOG_H

#include <QDialog>

namespace Ui {
class playerFilterDialog;
}

class playerFilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit playerFilterDialog(QWidget *parent = nullptr);
    ~playerFilterDialog();

private:
    Ui::playerFilterDialog *ui;
};

#endif // PLAYERFILTERDIALOG_H
