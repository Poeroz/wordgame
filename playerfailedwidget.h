#ifndef PLAYERFAILEDWIDGET_H
#define PLAYERFAILEDWIDGET_H

#include <QWidget>

namespace Ui {
class playerFailedWidget;
}

class playerFailedWidget : public QWidget {
    Q_OBJECT

public:
    explicit playerFailedWidget(QWidget *parent = nullptr);
    ~playerFailedWidget();

signals:
    void failedToGaming();

    void failedToChLevel();

private slots:
    void on_retryBtn_clicked();

    void on_returnBtn_clicked();

private:
    Ui::playerFailedWidget *ui;
};

#endif // PLAYERFAILEDWIDGET_H
