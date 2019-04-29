#include "playergamingwidget.h"
#include "ui_playergamingwidget.h"

playerGamingWidget::playerGamingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerGamingWidget) {
    ui->setupUi(this);

    ui->progressBar->setOrientation(Qt::Horizontal);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setValue(10);
    ui->progressBar->setTextVisible(false);
    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(updateProgressBar()));
    restTime = 10;

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
        if (!query.exec("select * from word order by random() limit 1")) {
            qDebug() << "query error";
        }
        else {
            if (query.next()) {
                ui->wordLabel->setText(query.value(TEXT).toString());
                ui->wordLabel->show();
                ui->wordLineEdit->setEnabled(false);
                myTimer->start(1000);
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
        ui->progressBar->setValue(restTime = 10);
        ui->wordLineEdit->clear();
        showNewWord();
    }
    else {
        QMessageBox::warning(this, tr("提示"), tr("闯关失败！"), QMessageBox::Ok);
        this->close();
    }
}
