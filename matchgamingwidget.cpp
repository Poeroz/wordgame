/**
 * @file matchgamingwidget.cpp
 *
 * @brief 匹配模式游戏界面。
 * @author 房庆凯 - 2017211131
 */

#include "matchgamingwidget.h"
#include "ui_matchgamingwidget.h"

matchGamingWidget::matchGamingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::matchGamingWidget) {
    ui->setupUi(this);

    /* 定时器初始化以及连接信号与槽 */
    myTimer = new QTimer(this);
    totalTime = new QElapsedTimer;
    connect(myTimer, SIGNAL(timeout()), this, SLOT(updateProgressBar()));

    /* 使用正则表达式来限制用户只可输入小写字母 */
    ui->wordLineEdit->setValidator(new QRegExpValidator(QRegExp("^[a-z]{1,18}$"), this));
}

matchGamingWidget::~matchGamingWidget() {
    delete ui;
}

void matchGamingWidget::init(QString text) {
    ui->wordLabel->hide();
    ui->passLabel->hide();
    ui->progressBar->hide();
    ui->statusLabel->hide();
    ui->wordLineEdit->hide();
    ui->okBtn->hide();
    ui->matchLabel->show();
    ui->matchLabel->setText(text);
    ui->cancelBtn->show();
}

void matchGamingWidget::end(QString text) {
    ui->wordLabel->hide();
    ui->passLabel->hide();
    ui->progressBar->hide();
    ui->statusLabel->hide();
    ui->wordLineEdit->hide();
    ui->okBtn->hide();
    ui->matchLabel->show();
    ui->matchLabel->setText(text);
}

void matchGamingWidget::start(const QVector<QString> &rhs) {
    wordlist.clear();
    for (int i = 0; i < rhs.size(); i++) {
        wordlist.push_back(rhs[i]);
    }

    ui->wordLabel->show();
    ui->passLabel->show();
    ui->progressBar->show();
    ui->statusLabel->show();
    ui->wordLineEdit->show();
    ui->okBtn->show();
    ui->matchLabel->hide();
    ui->cancelBtn->hide();

    ui->progressBar->setOrientation(Qt::Horizontal);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(5);
    ui->progressBar->setValue(5);
    ui->progressBar->setTextVisible(false);

    ui->statusLabel->clear();
    restTime = 5;
    passCnt = 0;
    totalTime->start();

    showNewWord();
}

void matchGamingWidget::showNewWord() {
    QString word = wordlist[passCnt++];
    ui->passLabel->setText(QString("%1/%2").arg(passCnt).arg(10));
    ui->wordLabel->setText(word);
    ui->wordLabel->show();

    ui->wordLineEdit->setEnabled(false);                                        /* 倒计时结束前将编辑框设置为不可编辑 */

    myTimer->start(1000);
}

void matchGamingWidget::updateProgressBar() {
    ui->progressBar->setValue(--restTime);

    /* 倒计时结束 */
    if (restTime == 0) {
        myTimer->stop();
        ui->wordLabel->hide();
        ui->wordLineEdit->setEnabled(true);                                     /* 将编辑框设置为可编辑 */
        ui->wordLineEdit->setFocus();
    }
}

void matchGamingWidget::on_okBtn_clicked() {
    QString userInput = ui->wordLineEdit->text();
    if (userInput == ui->wordLabel->text()) {
        ui->statusLabel->setText(tr("正确！"));
        ui->progressBar->setValue(restTime = 5);             /* 恢复倒计时时间，准备进入下一轮 */
        ui->wordLineEdit->clear();

        /* 通过当前关卡，进入下一关 */
        if (passCnt == 10) {
            int realTime = totalTime->elapsed() / 1000 + 1 - 5 * 10;
            passCnt = 0;
            emit endGame(realTime);
        }
        else {
            showNewWord();
        }
    }
    else {
        emit endGame(-1);
        ui->wordLineEdit->clear();
    }
}

void matchGamingWidget::on_cancelBtn_clicked() {
    emit cancelMatch();
}
