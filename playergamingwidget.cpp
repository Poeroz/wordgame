/**
 * @file playergamingwidget.cpp
 *
 * @brief 闯关者游戏界面。
 * @author 房庆凯 - 2017211131
 */

#include "playergamingwidget.h"
#include "ui_playergamingwidget.h"

playerGamingWidget::playerGamingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerGamingWidget) {
    ui->setupUi(this);

    /* 定时器初始化以及连接信号与槽 */
    myTimer = new QTimer(this);\
    connect(myTimer, SIGNAL(timeout()), this, SLOT(updateProgressBar()));
}

playerGamingWidget::~playerGamingWidget() {
    delete ui;
}

void playerGamingWidget::showNewWord() {
    worddbManager man;
    QString word = man.getRandWord(nowLevel + 2, nowLevel + 3); /* 显示一个当前对应难度的单词 */
    passCnt++;                                                  /* 当前轮数增加 */

    /* 显示当前的关卡数、轮数、单词等 */
    ui->levelLabel->setText(QString("第 %1 关").arg(nowLevel));
    ui->passLabel->setText(QString("%1/%2").arg(passCnt).arg(TOTAL));
    ui->wordLabel->setText(word);
    ui->wordLabel->show();

    ui->wordLineEdit->setEnabled(false);                        /* 倒计时结束前将编辑框设置为不可编辑 */

    myTimer->start(1000);                                       /* 启动定时器 */
}

void playerGamingWidget::updateProgressBar() {
    ui->progressBar->setValue(--restTime);

    /* 倒计时结束 */
    if (restTime == 0) {
        myTimer->stop();
        ui->wordLabel->hide();
        ui->wordLineEdit->setEnabled(true);                     /* 将编辑框设置为可编辑 */
        ui->wordLineEdit->setFocus();
    }
}

void playerGamingWidget::on_okBtn_clicked() {
    QString userInput = ui->wordLineEdit->text();
    if (userInput == ui->wordLabel->text()) {
        ui->statusLabel->setText(tr("正确！"));
        ui->progressBar->setValue(restTime = 5);                /* 恢复倒计时时间，准备进入下一轮 */
        ui->wordLineEdit->clear();

        /* 通过当前关卡，进入下一关 */
        if (passCnt == TOTAL) {
            emit gamingToPassed(nowLevel);
            nowLevel++;
            passCnt = 0;
        }

        showNewWord();
    }
    else {
        QMessageBox::warning(this, tr("提示"), tr("闯关失败！"), QMessageBox::Ok);
        ui->wordLineEdit->clear();
        emit gamingToFailed();
    }
}

void playerGamingWidget::on_exitBtn_clicked() {
    emit gamingToChLevel();
}

void playerGamingWidget::init(int levelId) {
    /* 进度条属性设置 */
    ui->progressBar->setOrientation(Qt::Horizontal);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(5);
    ui->progressBar->setValue(5);
    ui->progressBar->setTextVisible(false);

    restTime = 5;                                               /* 初始倒计时设置为 5 秒 */
    passCnt = 0;                                                /* 初始将当前轮数设置为 0 */
    if (levelId != -1) {
        nowLevel = levelId;                                     /* 初始化当前关卡 */
    }

    showNewWord();                                              /* 显示第一个单词 */
}

void playerGamingWidget::stop() {
    myTimer->stop();
}
