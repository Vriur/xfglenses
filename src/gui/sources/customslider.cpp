#include "src/gui/headers/customslider.h"
#include "ui_customslider.h"

using std::string;
using std::round;

CustomSlider::CustomSlider(QWidget *parent, ModelParameter *parameter)
    : QWidget(parent)
    , ui(new Ui::CustomSlider)
{
    ui->setupUi(this);

    this->name = parameter->getName();
    this->currentValue = parameter->getCurrentValue();
    this->initialValue = parameter->getCurrentValue();
    this->maxValue = parameter->getMaxValue();
    this->minValue = parameter->getMinValue();

    ui->NameLabel->setText(QString::fromStdString(name));
    ui->ValueLabel->setText(QString::number(currentValue));
    ui->Slider->setMaximum((int) this->maxValue * 100);
    ui->Slider->setMinimum((int) this->minValue * 100);
    ui->Slider->setValue((int) this->currentValue * 100);

    connect(this->ui->Slider, SIGNAL(valueChanged(int)), this, SLOT(updateLabel(int)));
}

CustomSlider::~CustomSlider()
{
    delete ui;
}

void CustomSlider::updateLabel(int currentValue){
    double newValue = (double) currentValue / 100;
    ui->ValueLabel->setText(QString::number(newValue));
    this->currentValue = newValue;

    emit updateParameterValue(newValue);
}

void CustomSlider::setName(string name){
    this->name = name;
}

string CustomSlider::getName(){
    return this->name;
}

void CustomSlider::setCurrentValue(double currentValue){
    this->currentValue = currentValue;
}

double CustomSlider::getCurrentValue(){
    return this->currentValue;
}
