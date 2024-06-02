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

    sourceType = "Source Menu";
    imageFilePath = "";
}

SimulationParameters::~SimulationParameters(){
    delete this;
}

void SimulationParameters::setCausticDX(double causticDX){
    this->causticDX = causticDX;
}

double SimulationParameters::getCausticDX(){
    return this->causticDX;
}

void SimulationParameters::setCausticTOL(double causticTOL){
    this->causticTOL = causticTOL;
}

double SimulationParameters::getCausticTOL(){
    return this->causticTOL;
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

void SimulationParameters::setSourcePositionX(double x){
    this->sourcePosition.first = x;
}

void SimulationParameters::setSourcePositionY(double y){
    this->sourcePosition.second = y;
}

pair<double, double> SimulationParameters::getSourcePosition(){
    return this->sourcePosition;
}

void SimulationParameters::setAnimationSourceInitialPositionX(double x){
    this->animationSourceInitialPosition.first = x;
}

void SimulationParameters::setAnimationSourceInitialPositionY(double y){
    this->animationSourceInitialPosition.second = y;
}

pair<double, double> SimulationParameters::getAnimationSourceInitialPosition(){
    return this->animationSourceInitialPosition;
}

void SimulationParameters::setAnimationSourceFinalPositionX(double x){
    this->animationSourceFinalPosition.first = x;
}

void SimulationParameters::setAnimationSourceFinalPositionY(double y){
    this->animationSourceFinalPosition.second = y;
}

pair<double, double> SimulationParameters::getAnimationSourceFinalPosition(){
    return this->animationSourceFinalPosition;
}

void SimulationParameters::setShowInGraph(string key, bool value){
    qDebug() << key << " " << value;
    this->showInGraph[key] = value;
}

bool SimulationParameters::getShowInGraph(string key){
    return this->showInGraph[key];
}

void SimulationParameters::createImage(double x, double y){
    pair<double, double> *newImage = new pair(x, y);
    this->images.push_back(newImage);
}

void SimulationParameters::editImageX(double x, int index){
    this->images[index]->first = x;
}

void SimulationParameters::editImageY(double y, int index){
    this->images[index]->second = y;
}

void SimulationParameters::deleteImage(int index){
    this->images.erase(std::next(images.begin(), index));
}

void SimulationParameters::clearImages(){
    this->images.clear();
}

pair<double, double>* SimulationParameters::getImage(int index){
    return this->images[index];
}

vector<pair<double, double>*> SimulationParameters::getImages(){
    return this->images;
}

int SimulationParameters::getImagesLength(){
    return this->images.size();
}
