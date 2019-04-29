#ifndef PLAYERGAMINGWIDGET_H
#define PLAYERGAMINGWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QProgressBar>
#include <QMessageBox>
#include <QPair>
#include "worddb.h"

namespace Ui {
class playerGamingWidget;
}

const int TOTAL = 5;

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
    int restTime, nowLevel, passCnt;
    QTimer *myTimer;
};

#endif // PLAYERGAMINGWIDGET_H

