#include "playergamingwidget.h"
#include "ui_playergamingwidget.h"

playerGamingWidget::playerGamingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerGamingWidget) {
    ui->setupUi(this);

    ui->progressBar->setOrientation(Qt::Horizontal);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(3);
    ui->progressBar->setInvertedAppearance(true);
    ui->progressBar->setTextVisible(false);

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
                ui->progressBar->reset();
            }
        }
    }
}
