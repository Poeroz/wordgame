#include "chooselevelwidget.h"
#include "ui_chooselevelwidget.h"

chooseLevelWidget::chooseLevelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseLevelWidget) {
    ui->setupUi(this);
    ui->glot->setSpacing(10);
    ui->glot->setVerticalSpacing(15);
    for (int i = 0; i < 16; ++i) {
        btnlst.push_back(new CustomizedButton);
        btnlst.back()->setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored));
        btnlst.back()->setText(QString().setNum(i + 1));
        btnlst.back()->id = i + 1;
        connect(btnlst.back(), SIGNAL(clicked()), this, SLOT(getBtnId()));
        ui->glot->addWidget(btnlst.back(), i >> 2, i & 3);
    }
}

chooseLevelWidget::~chooseLevelWidget() {
    delete ui;
}

void chooseLevelWidget::getBtnId() {
    CustomizedButton *Btn=qobject_cast<CustomizedButton*>(sender());
    emit chLevelToGaming(Btn->id);
}

CustomizedButton::CustomizedButton() : QPushButton () {}

void chooseLevelWidget::on_pushButton_clicked() {
    emit chLevelToReady();
}
