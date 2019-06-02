/**
 * @file endmatchwidget.cpp
 *
 * @brief 匹配模式结束后的界面。
 * @author 房庆凯 - 2017211131
 */

#include "endmatchwidget.h"
#include "ui_endmatchwidget.h"

endMatchWidget::endMatchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::endMatchWidget) {
    ui->setupUi(this);
}

endMatchWidget::~endMatchWidget() {
    delete ui;
}

void endMatchWidget::init(bool winState, int getExp) {
    if (winState) {
        ui->winLabel->setText(tr("你赢了"));
    }
    else {
        ui->winLabel->setText(tr("你输了"));
    }
    ui->expLabel->setText(QString("获得经验值：%1").arg(getExp));
}

void endMatchWidget::on_backBtn_clicked() {
    emit endToReady();
}
