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
    myTimer = new QTimer(this);
    totalTime = new QElapsedTimer;
    connect(myTimer, SIGNAL(timeout()), this, SLOT(updateProgressBar()));

    /* 使用正则表达式来限制用户只可输入小写字母 */
    ui->wordLineEdit->setValidator(new QRegExpValidator(QRegExp("^[a-z]{1,18}$"), this));
}

playerGamingWidget::~playerGamingWidget() {
    delete ui;
}

void playerGamingWidget::showNewWord() {
    worddbManager man;
    QString word = man.getRandWord(MIN_LENGTH[nowLevel], MAX_LENGTH[nowLevel]); /* 显示一个当前对应难度的单词 */
    passCnt++;                                                                  /* 当前轮数增加 */
    totalLength += word.length();                                               /* 统计本关单词总长度 */

    /* 显示当前的关卡数、轮数、单词等 */
    ui->levelLabel->setText(QString("第 %1 关").arg(nowLevel));
    ui->passLabel->setText(QString("%1/%2").arg(passCnt).arg(TOTAL_ROUND[nowLevel]));
    ui->wordLabel->setText(word);
    ui->wordLabel->show();

    ui->wordLineEdit->setEnabled(false);                                        /* 倒计时结束前将编辑框设置为不可编辑 */

    myTimer->start(1000);                                                       /* 启动定时器 */
}

void playerGamingWidget::updateProgressBar() {
    ui->progressBar->setValue(--restTime);

    /* 倒计时结束 */
    if (restTime == 0) {
        myTimer->stop();
        ui->wordLabel->hide();
        ui->wordLineEdit->setEnabled(true);                                     /* 将编辑框设置为可编辑 */
        ui->wordLineEdit->setFocus();
    }
}

void playerGamingWidget::on_okBtn_clicked() {
    QString userInput = ui->wordLineEdit->text();
    if (userInput == ui->wordLabel->text()) {
        ui->statusLabel->setText(tr("正确！"));
        ui->progressBar->setValue(restTime = TOTAL_TIME[nowLevel]);             /* 恢复倒计时时间，准备进入下一轮 */
        ui->wordLineEdit->clear();

        /* 通过当前关卡，进入下一关 */
        if (passCnt == TOTAL_ROUND[nowLevel]) {
            int realTime = totalTime->elapsed() / 1000 + 1 - TOTAL_TIME[nowLevel] * TOTAL_ROUND[nowLevel];
            int plusExp = nowLevel;
            if (realTime >= totalLength / 2) {
                plusExp = qCeil(plusExp * qExp(1 - qreal(realTime) / qreal(totalLength / 2)));
            }
            emit gamingToPassed(nowLevel, plusExp);
            nowLevel++;
            passCnt = 0;
        }
        else {
            showNewWord();
        }
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
    if (levelId != -1) {
        nowLevel = levelId;                                                     /* 初始化当前关卡 */
    }

    /* 进度条属性设置 */
    ui->progressBar->setOrientation(Qt::Horizontal);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(TOTAL_TIME[nowLevel]);
    ui->progressBar->setValue(TOTAL_TIME[nowLevel]);
    ui->progressBar->setTextVisible(false);

    ui->statusLabel->clear();
    restTime = TOTAL_TIME[nowLevel];                                            /* 初始倒计时设置为 5 秒 */
    passCnt = 0;                                                                /* 初始将当前轮数设置为 0 */
    totalLength = 0;
    totalTime->start();

    showNewWord();                                                              /* 显示第一个单词 */
}

void playerGamingWidget::stop() {
    myTimer->stop();
}
