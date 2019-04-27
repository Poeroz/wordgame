#ifndef QUESTIONERWINDOW_H
#define QUESTIONERWINDOW_H

#include <QMainWindow>
#include "questioner.h"
#include "userdb.h"
#include "alluserwidget.h"


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

private:
    Ui::questionerWindow *ui;
};

#endif // QUESTIONERWINDOW_H
