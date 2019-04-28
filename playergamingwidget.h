#ifndef PLAYERGAMINGWIDGET_H
#define PLAYERGAMINGWIDGET_H

#include <QWidget>
#include <QProgressBar>
#include "worddb.h"

namespace Ui {
class playerGamingWidget;
}

class playerGamingWidget : public QWidget {
    Q_OBJECT

public:
    explicit playerGamingWidget(QWidget *parent = nullptr);
    ~playerGamingWidget();

private:
    Ui::playerGamingWidget *ui;
    void showNewWord();
};

#endif // PLAYERGAMINGWIDGET_H

