#ifndef MATCHGAMINGWIDGET_H
#define MATCHGAMINGWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <QProgressBar>
#include <QMessageBox>
#include <QPair>
#include <QtMath>
#include <QRegExpValidator>

namespace Ui {
class matchGamingWidget;
}

class matchGamingWidget : public QWidget {
    Q_OBJECT

public:
    explicit matchGamingWidget(QWidget *parent = nullptr);
    ~matchGamingWidget();
    void init(QString text);
    void start(const QVector<QString> &rhs);

signals:
    void endGame(int totalTime);

private slots:
    void updateProgressBar();

    void on_okBtn_clicked();

private:
    Ui::matchGamingWidget *ui;

    /**
     * @brief 显示一个新单词。
     */
    void showNewWord();

    QVector<QString> wordlist;
    int restTime;                                       /**< 本轮剩余时间。 */
    int nowLevel;                                       /**< 当前关卡数。 */
    int passCnt;                                        /**< 本关当前轮数。 */
    QElapsedTimer *totalTime;                           /**< 本关花费的总时间。 */
    QTimer *myTimer;                                    /**< 倒计时用定时器。 */
};

#endif // MATCHGAMINGWIDGET_H
