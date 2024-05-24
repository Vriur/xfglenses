#include "src/gui/headers/customslider.h"
#include "ui_customslider.h"

#include <QDebug>

using std::string;
using std::round;

CustomSlider::CustomSlider(QWidget *parent, ModelParameter *parameter)
    : QWidget(parent)
    , ui(new Ui::CustomSlider)
{
    ui->setupUi(this);

    if(parameter != nullptr){
        this->setName(parameter->getName());
        this->setMinValue(parameter->getMinValue());
        this->setMaxValue(parameter->getMaxValue());
        this->setCurrentValue(parameter->getCurrentValue());
    }

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
    ui->NameLabel->setText(QString::fromStdString(name));
}

string CustomSlider::getName(){
    return this->name;
}

void CustomSlider::setCurrentValue(double currentValue){
    this->currentValue = currentValue;
    ui->ValueLabel->setText(QString::number(currentValue));
    ui->Slider->setValue((int) (currentValue * 100));
}

double CustomSlider::getCurrentValue(){
    return this->currentValue;
}

void CustomSlider::setMinValue(double minValue){
    this->minValue = minValue;
    ui->Slider->setMinimum((int) minValue * 100);
}

double CustomSlider::getMinValue(){
    return this->minValue;
}

void CustomSlider::setMaxValue(double maxValue){
    this->maxValue = maxValue;
    ui->Slider->setMaximum((int) maxValue * 100);
}

double CustomSlider::getMaxValue(){
    return this->maxValue;
}

void CustomSlider::on_Slider_valueChanged(int value)
{
    emit this->updateParameterValue((double) value / 100);
}

