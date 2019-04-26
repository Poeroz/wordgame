#ifndef PLAYERWINDOW_H
#define PLAYERWINDOW_H

#include <QMainWindow>
#include "player.h"
#include "userdb.h"

namespace Ui {
class playerWindow;
}

class playerWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit playerWindow(QWidget *parent = nullptr);
    void init(player user);
    ~playerWindow();

private:
    Ui::playerWindow *ui;
};

#endif // PLAYERWINDOW_H
