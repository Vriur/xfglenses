#include "src/gui/headers/causticdialog.h"
#include "ui_causticdialog.h"

CausticDialog::CausticDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CausticDialog)
{
    ui->setupUi(this);
}

CausticDialog::~CausticDialog()
{
    delete ui;
}
