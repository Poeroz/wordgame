#ifndef QUESTIONERGAMINGWIDGET_H
#define QUESTIONERGAMINGWIDGET_H

#include <QMessageBox>
#include <QWidget>
#include "worddb.h"

namespace Ui {
class questionerGamingWidget;
}

class questionerGamingWidget : public QWidget {
    Q_OBJECT

public:
    explicit questionerGamingWidget(QWidget *parent = nullptr);
    ~questionerGamingWidget();

private slots:
    void on_okBtn_clicked();

    void on_pushButton_clicked();

private:
    Ui::questionerGamingWidget *ui;
};

#endif // QUESTIONERGAMINGWIDGET_H
