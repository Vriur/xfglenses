#include "modelsdialog.h"
#include "ui_modelsdialog.h"

/*#include "customslider.h"
vector<double> sliderParams{2.30, 10.00, 0.00};
    CustomSlider *instance = new CustomSlider(this, "K", sliderParams);
    ui->horizontalLayout_4->addWidget(instance);*/


ModelsDialog::ModelsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModelsDialog)
{
    ui->setupUi(this);
}

ModelsDialog::~ModelsDialog()
{
    delete ui;
}
