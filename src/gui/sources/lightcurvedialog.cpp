#include "src/gui/headers/lightcurvedialog.h"
#include "ui_lightcurvedialog.h"

LightCurveDialog::LightCurveDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LightCurveDialog)
{
    ui->setupUi(this);
}

LightCurveDialog::~LightCurveDialog()
{
    delete ui;
}
