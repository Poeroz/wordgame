#ifndef PLAYERPASSEDWIDGET_H
#define PLAYERPASSEDWIDGET_H

#include <QWidget>

namespace Ui {
class playerPassedWidget;
}

class playerPassedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit playerPassedWidget(QWidget *parent = nullptr);
    ~playerPassedWidget();

signals:
    void passedToGaming();

    void passedToChLevel();

private slots:
    void on_nextBtn_clicked();

    void on_returnBtn_clicked();

private:
    Ui::playerPassedWidget *ui;
};

#endif // PLAYERPASSEDWIDGET_H
