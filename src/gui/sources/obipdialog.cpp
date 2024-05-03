#include "src/gui/headers/obipdialog.h"
#include "ui_obipdialog.h"

OBIPDialog::OBIPDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OBIPDialog)
{
    ui->setupUi(this);
}

OBIPDialog::~OBIPDialog()
{
    delete ui;
}
