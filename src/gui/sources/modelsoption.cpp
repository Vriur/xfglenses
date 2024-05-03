#include "src/gui/headers/modelsoption.h"
#include "ui_modelsoption.h"

#include "src/gui/headers/customslider.h"

#include <QDebug>
#include <QPushButton>
#include <QObjectList>

ModelsOption::ModelsOption(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModelsOption)
{
    ui->setupUi(this);
}

ModelsOption::~ModelsOption()
{
    delete ui;
}

void ModelsOption::on_ModelMenuCmBox_currentTextChanged(const QString &arg1)
{
    cleanScrollArea();
    vector<double> sliderParams{2.30, 10.00, 0.00}; // Initial Value, Max Value, Min Value
    CustomSlider *instance3 = new CustomSlider(this, "K", sliderParams);
    this->ui->ScrollLayout->addWidget(instance3);
    //qDebug() << scrollAreaLayout->count();
}


void ModelsOption::cleanScrollArea(){
    while(this->ui->ScrollLayout->count() != 0){
        QLayoutItem *item = this->ui->ScrollLayout->takeAt(0);
        delete item->widget();
        delete item;
    }
}
