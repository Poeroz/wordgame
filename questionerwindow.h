#ifndef QUESTIONERWINDOW_H
#define QUESTIONERWINDOW_H

#include <QMainWindow>
#include "questioner.h"
#include "userdbmanager.h"
#include "alluserwidget.h"
#include "questionergamingwidget.h"

namespace Ui {
class questionerWindow;
}

class questionerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit questionerWindow(QWidget *parent = nullptr);
    ~questionerWindow();
    void init(questioner user);

private slots:
    void on_allUserBtn_clicked();

    void on_startBtn_clicked();

private:
    Ui::questionerWindow *ui;
};

#endif // QUESTIONERWINDOW_H
