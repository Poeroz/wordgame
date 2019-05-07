#ifndef CHOOSELEVELWIDGET_H
#define CHOOSELEVELWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QPushButton>

namespace Ui {
class chooseLevelWidget;
}

class CustomizedButton : public QPushButton {
    Q_OBJECT
public:
    CustomizedButton();
    int id;
};

class chooseLevelWidget : public QWidget {
    Q_OBJECT

public:
    explicit chooseLevelWidget(QWidget *parent = nullptr);
    ~chooseLevelWidget();

private:
    QVector<CustomizedButton*> btnlst;
    Ui::chooseLevelWidget *ui;

signals:
    void chLevelToGaming(int levelId);
    void chLevelToReady();

private slots:
    void getBtnId();
    void on_pushButton_clicked();
};

#endif // CHOOSELEVELWIDGET_H
