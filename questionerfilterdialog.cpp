#include "questionerfilterdialog.h"
#include "ui_questionerfilterdialog.h"

questionerFilterDialog::questionerFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::questionerFilterDialog)
{
    ui->setupUi(this);
}

questionerFilterDialog::~questionerFilterDialog()
{
    delete ui;
}
