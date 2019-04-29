#include "playergamingwidget.h"
#include "ui_playergamingwidget.h"

playerGamingWidget::playerGamingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerGamingWidget) {
    ui->setupUi(this);

    ui->progressBar->setOrientation(Qt::Horizontal);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(5);
    ui->progressBar->setValue(5);
    ui->progressBar->setTextVisible(false);
    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(updateProgressBar()));
    restTime = 5;
    nowLevel = 1;
    passCnt = 0;

    showNewWord();
}

playerGamingWidget::~playerGamingWidget() {
    delete ui;
}

void playerGamingWidget::showNewWord() {
    QSqlDatabase worddb;
    worddb = QSqlDatabase::database("wordConnect");
    if (!worddb.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlQuery query(worddb);
        QString str = "select * from word where length >= :min and length <= :max order by random() limit 1";
        query.prepare(str);
        query.bindValue(":min", nowLevel + 2);
        query.bindValue(":max", nowLevel + 3);
        if (!query.exec()) {
            qDebug() << "query error";
        }
        else {
            if (query.next()) {
                passCnt++;
                ui->levelLabel->setText(QString("第 %1 关").arg(nowLevel));
                ui->passLabel->setText(QString("%1/%2").arg(passCnt).arg(TOTAL));
                ui->wordLabel->setText(query.value(TEXT).toString());
                ui->wordLabel->show();
                ui->wordLineEdit->setEnabled(false);
                myTimer->start(1000);
                if (passCnt == TOTAL) {
                    nowLevel++;
                    passCnt = 0;
                }
            }
        }
    }
}

void playerGamingWidget::updateProgressBar() {
    ui->progressBar->setValue(--restTime);
    if (restTime == 0) {
        myTimer->stop();
        ui->wordLabel->hide();
        ui->wordLineEdit->setEnabled(true);
        ui->wordLineEdit->setFocus();
    }
}

void playerGamingWidget::on_okBtn_clicked() {
    QString userInput = ui->wordLineEdit->text();
    if (userInput == ui->wordLabel->text()) {
        ui->statusLabel->setText(tr("正确！"));
        ui->progressBar->setValue(restTime = 5);
        ui->wordLineEdit->clear();
        showNewWord();
    }
    else {
        QMessageBox::warning(this, tr("提示"), tr("闯关失败！"), QMessageBox::Ok);
        this->close();
    }
}
