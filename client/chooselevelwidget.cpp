/**
 * @file chooselevelwidget.cpp
 *
 * @brief 游戏菜单（选择关卡）界面。
 * @author 房庆凯 - 2017211131
 */

#include "chooselevelwidget.h"
#include "ui_chooselevelwidget.h"

chooseLevelWidget::chooseLevelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseLevelWidget) {
    ui->setupUi(this);

    /* 设置按钮的间距 */
    ui->glot->setSpacing(10);
    ui->glot->setVerticalSpacing(15);

    /* 初始化所有按钮 */
    for (int i = 0; i < 16; i++) {
        btnlst.push_back(new CustomizedButton);
        btnlst.back()->setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored));
        btnlst.back()->setText(QString().setNum(i + 1));
        btnlst.back()->setId(i + 1);
        connect(btnlst.back(), SIGNAL(clicked()), this, SLOT(getBtnId()));          /* 连接信号和槽 */
        ui->glot->addWidget(btnlst.back(), i >> 2, i & 3);
    }
}

CustomizedButton::CustomizedButton() : QPushButton () {}

void CustomizedButton::setId(int _id) {
    this->id = _id;
}

int CustomizedButton::getId() {
    return this->id;
}

chooseLevelWidget::~chooseLevelWidget() {
    delete ui;
}

void chooseLevelWidget::init(int maxLevel) {
    for (int i = 0; i <= maxLevel; i++) {
        btnlst[i]->setEnabled(true);
    }
    for (int i = maxLevel + 1; i < 16; i++) {
        btnlst[i]->setEnabled(false);
    }
}

void chooseLevelWidget::getBtnId() {
    CustomizedButton *Btn=qobject_cast<CustomizedButton*>(sender());
    emit chLevelToGaming(Btn->getId());
}

void chooseLevelWidget::on_pushButton_clicked() {
    emit chLevelToReady();
}
