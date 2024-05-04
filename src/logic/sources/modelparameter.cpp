#include "../headers/modelparameter.h"

ModelParameter::ModelParameter(string name, double currentValue, double maxValue, double minValue){
    this->name = name;
    this->currentValue = currentValue;
    this->maxValue = maxValue;
    this->minValue = minValue;
}

ModelParameter::~ModelParameter(){
    delete this;
}

void ModelParameter::setName(string name){
    this->name = name;
}

void ModelParameter::setCurrentValue(double currentValue){
    this->currentValue = currentValue;
}

void ModelParameter::setMaxValue(double maxValue){
    this->maxValue = maxValue;
}

void ModelParameter::setMinValue(double minValue){
    this->minValue = minValue;
}

string ModelParameter::getName(){
    return this->name;
}

double ModelParameter::getCurrentValue(){
    return this->currentValue;
}

double ModelParameter::getMaxValue(){
    return this->maxValue;
}

double ModelParameter::getMinValue(){
    return this->minValue;
}
