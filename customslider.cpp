#include "customslider.h"
#include "ui_customslider.h"

CustomSlider::CustomSlider(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CustomSlider)
{
    ui->setupUi(this);
    connect(this->ui->Slider, SIGNAL(valueChanged(int)), this->ui->ValueLabel, SLOT(setNum(int)));
}

CustomSlider::~CustomSlider()
{
    delete ui;
}
