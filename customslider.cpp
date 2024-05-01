#include "customslider.h"
#include "ui_customslider.h"

/*#include <QDebug>
qDebug() << Lo que quiere mostrar;*/

using std::string;
using std::round;

CustomSlider::CustomSlider(QWidget *parent, const string &name, const vector<double> &sliderParams)
    : QWidget(parent)
    , ui(new Ui::CustomSlider)
{
    ui->setupUi(this);

    this->name = name;
    this->currentValue = sliderParams[0];
    this->initialValue = sliderParams[0];
    this->maxValue = sliderParams[1];
    this->minValue = sliderParams[2];

    ui->NameLabel->setText(QString::fromStdString(name));
    ui->ValueLabel->setText(QString::number(currentValue));
    ui->Slider->setValue(mapDoubleToInt(currentValue));

    connect(this->ui->Slider, SIGNAL(valueChanged(int)), this, SLOT(updateLabel(int)));
}

CustomSlider::~CustomSlider()
{
    delete ui;
}

void CustomSlider::updateLabel(int currentValue){
    double currentValueDb = mapIntToDouble(currentValue);
    ui->ValueLabel->setText(QString::number(currentValueDb));
    this->currentValue = currentValueDb;
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

int CustomSlider::mapDoubleToInt(double currentValue){
    double interval = maxValue - minValue;
    double percentageEquivalence = interval / 100;
    return round((currentValue - minValue) / percentageEquivalence);
}

double CustomSlider::mapIntToDouble(int currentValue){
    double interval = maxValue - minValue;
    double percentageEquivalence = interval / 100;
    return minValue + (currentValue * percentageEquivalence);
}
