#ifndef ALLUSERWIDGET_H
#define ALLUSERWIDGET_H

#include <QWidget>
#include <QSqlTableModel>
#include <QAbstractItemView>
#include "userdb.h"

namespace Ui {
class allUserWidget;
}

class allUserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit allUserWidget(QWidget *parent = nullptr);
    ~allUserWidget();

private slots:
    void sortByColumn(int col);

    void on_playerBtn_clicked();

    void on_questionerBtn_clicked();

private:
    Ui::allUserWidget *ui;
    void showPlayerTable();
    void showQuestionerTable();
};

#endif // ALLUSERWIDGET_H
