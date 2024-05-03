#include "src/gui/headers/fittingdialog.h"
#include "ui_fittingdialog.h"

FittingDialog::FittingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FittingDialog)
{
    ui->setupUi(this);
}

FittingDialog::~FittingDialog()
{
    delete ui;
}
