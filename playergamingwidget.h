#ifndef PLAYERGAMINGWIDGET_H
#define PLAYERGAMINGWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QProgressBar>
#include <QMessageBox>
#include "worddb.h"

namespace Ui {
class playerGamingWidget;
}

class playerGamingWidget : public QWidget {
    Q_OBJECT

public:
    explicit playerGamingWidget(QWidget *parent = nullptr);
    ~playerGamingWidget();

private slots:
    void updateProgressBar();

    void on_okBtn_clicked();

private:
    Ui::playerGamingWidget *ui;
    void showNewWord();
    int restTime;
    QTimer *myTimer;
};

#endif // PLAYERGAMINGWIDGET_H

