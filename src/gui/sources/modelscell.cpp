#include "src/gui/headers/modelscell.h"
#include "ui_modelscell.h"

#include "src/gui/headers/customslider.h"

#include <QPushButton>
#include <QObjectList>

ModelsCell::ModelsCell(QWidget *parent, Model *model, int index)
    : QDialog(parent)
    , ui(new Ui::ModelsCell)
{
    ui->setupUi(this);

    this->index = index;
    if(model != nullptr){
        loadModel(model);
    }
}

ModelsCell::~ModelsCell()
{
    delete ui;
}

void ModelsCell::on_ModelMenuCmBox_currentTextChanged(const QString &modelName)
{
    emit changeSimulationModel(modelName.toStdString(), this->index);
}

void ModelsCell::loadModel(Model *model){
    string modelName = model->getName();
    this->ui->ModelMenuCmBox->setCurrentText(QString::fromStdString(model->getName()));
    this->loadParameters(model->getParameters(), this->index);
}

void ModelsCell::cleanScrollArea(){
    while(parametersSliders.size()){
        this->parametersSliders[0]->close();
        this->parametersSliders.erase(parametersSliders.begin());
    }
}

void ModelsCell::on_DeleteBtn_clicked()
{
    emit this->deleteThisCell(this->index);
}

void ModelsCell::loadParameters(vector<ModelParameter*> parameters, int index){
    if(this->index == index){
        cleanScrollArea();

        for(int index = 0; index < (int) parameters.size(); index++){
            CustomSlider *newCustomSlider = new CustomSlider(this, parameters.at(index));
            newCustomSlider->setAttribute(Qt::WA_DeleteOnClose);
            this->ui->ScrollLayout->addWidget(newCustomSlider);
            this->parametersSliders.push_back(newCustomSlider);

            connect(newCustomSlider, SIGNAL(updateParameterValue(double)), parameters.at(index), SLOT(setCurrentValue(double)));
        }
    }
}

void ModelsCell::setIndex(int index){
    this->index = index;
}

int ModelsCell::getIndex(){
    return this->index;
}

