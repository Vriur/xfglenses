#include "../headers/simulationparameters.h"

#include <QDebug>

SimulationParameters::SimulationParameters() {
    showInGraph["Caustics"] = false;
    showInGraph["Contour"] = false;
    showInGraph["CriticalCurves"] = false;
    showInGraph["Grid"] = false;
    showInGraph["Images"] = false;
    showInGraph["Inversion"] = false;
    showInGraph["RayPlot"] = false;
    showInGraph["Roots"] = false;
    showInGraph["R_E"] = false;
    showInGraph["Smooth"] = false;
    showInGraph["Source"] = false;
    showInGraph["TimeDelay"] = false;

    // First is X and second is Y.
    sourcePosition.first = 0.0;
    sourcePosition.second = 0.0;

    animationSourceInitialPosition.first = 0.0;
    animationSourceInitialPosition.second = 0.0;

    animationSourceFinalPosition.first = 0.0;
    animationSourceFinalPosition.second = 0.0;

    causticDX = 0.01;
    causticTOL = 0.1;

    sourceN = 4;
    sourceType = "Source Menu";
    imageFilePath = "";
}

SimulationParameters::~SimulationParameters(){
    delete this;
}

void SimulationParameters::setCausticDX(double causticDX){
    qDebug() << causticDX;
    this->causticDX = causticDX;
}

double SimulationParameters::getCausticDX(){
    return this->causticDX;
}

void SimulationParameters::setCausticTOL(double causticTOL){
    qDebug() << causticTOL;
    this->causticTOL = causticTOL;
}

double SimulationParameters::getCausticTOL(){
    return this->causticTOL;
}

void SimulationParameters::setSourceN(int sourceN){
    qDebug() << sourceN;
    this->sourceN = sourceN;
}

int SimulationParameters::getSourceN(){
    return this->sourceN;
}

void SimulationParameters::setSourceType(string sourceType){
    qDebug() << sourceType;
    this->sourceType = sourceType;
}

string SimulationParameters::getSourceType(){
    return this->sourceType;
}

void SimulationParameters::setImageFilePath(string imageFilePath){
    qDebug() << imageFilePath;
    this->imageFilePath = imageFilePath;
}

string SimulationParameters::getImageFilePath(){
    return this->imageFilePath;
}

void SimulationParameters::setSourcePositionX(double valueX){
    qDebug() << valueX;
    this->sourcePosition.first = valueX;
}

void SimulationParameters::setSourcePositionY(double valueY){
    qDebug() << valueY;
    this->sourcePosition.second = valueY;
}

pair<double, double> SimulationParameters::getSourcePosition(){
    return this->sourcePosition;
}

void SimulationParameters::setAnimationSourceInitialPositionX(double valueX){
    qDebug() << "IX: " << valueX;
    this->animationSourceInitialPosition.first = valueX;
}

void SimulationParameters::setAnimationSourceInitialPositionY(double valueY){
    qDebug() << "IY: " << valueY;
    this->animationSourceInitialPosition.second = valueY;
}

pair<double, double> SimulationParameters::getAnimationSourceInitialPosition(){
    qDebug() << this->animationSourceInitialPosition.first << " " << this->animationSourceInitialPosition.second;
    return this->animationSourceInitialPosition;
}

void SimulationParameters::setAnimationSourceFinalPositionX(double valueX){
    qDebug() << "FX: " << valueX;
    this->animationSourceFinalPosition.first = valueX;
}

void SimulationParameters::setAnimationSourceFinalPositionY(double valueY){
    qDebug() << "FY: " << valueY;
    this->animationSourceFinalPosition.second = valueY;
}

pair<double, double> SimulationParameters::getAnimationSourceFinalPosition(){
    return this->animationSourceFinalPosition;
}

void SimulationParameters::setShowInGraph(string key, bool value){
    qDebug() << value;
    this->showInGraph[key] = value;
}

bool SimulationParameters::getShowInGraph(string key){
    return this->showInGraph[key];
}
