#include "src/gui/headers/fittingdialog.h"
#include "ui_fittingdialog.h"

FittingDialog::FittingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FittingDialog)
{
    ui->setupUi(this);

    this->ui->WA->setName("W_A");
    this->ui->WA->setCurrentValue((double) 0.00);
    this->ui->WA->setMinValue((double) 0.00);
    this->ui->WA->setMaxValue((double) 1.00);

    this->ui->WP->setName("W_P");
    this->ui->WP->setCurrentValue((double) 0.00);
    this->ui->WP->setMinValue((double) 0.00);
    this->ui->WP->setMaxValue((double) 1.00);
}

FittingDialog::~FittingDialog()
{
    delete ui;
}

void FittingDialog::on_DoneBtn_clicked()
{
    this->close();
}

