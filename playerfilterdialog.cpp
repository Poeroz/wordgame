#include "playerfilterdialog.h"
#include "ui_playerfilterdialog.h"

playerFilterDialog::playerFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playerFilterDialog)
{
    ui->setupUi(this);
}

playerFilterDialog::~playerFilterDialog()
{
    delete ui;
}
