#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include "player.h"
#include "userdb.h"
#include "alluserwidget.h"

namespace Ui {
class playerWindow;
}

class playerWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit playerWindow(QWidget *parent = nullptr);
    void init(player user);
    ~playerWindow();

private slots:
    void on_allUserBtn_clicked();

private:
    Ui::playerWindow *ui;
};

#endif // PLAYERWINDOW_H
