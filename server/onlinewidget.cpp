/**
 * @file onlinewidget.cpp
 *
 * @brief 显示所有在线玩家。
 * @author 房庆凯 - 2017211131
 */

#include "onlinewidget.h"
#include "ui_onlinewidget.h"

onlineWidget::onlineWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::onlineWidget) {
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(1);
    QStringList header;
    header << "在线玩家用户名";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width());
    ui->tableWidget->verticalHeader()->hide();
}

onlineWidget::~onlineWidget() {
    delete ui;
}

void onlineWidget::refreshTable(QVector<QString> userList) {
    qDebug() << "refresh";
    ui->tableWidget->setRowCount(userList.size());

    for (int i = 0; i < userList.size(); i++) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(userList[i]));
        ui->tableWidget->item(i, 0)->setTextAlignment(Qt::AlignCenter);
    }
}
