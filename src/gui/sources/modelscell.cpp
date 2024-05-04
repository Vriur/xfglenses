#include "src/gui/headers/modelscell.h"
#include "ui_modelscell.h"

#include "src/gui/headers/customslider.h"

#include <QPushButton>
#include <QObjectList>
#include <QDebug>

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
    this->loadParameters(model->getParameters());
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

void ModelsCell::loadParameters(vector<ModelParameter*> parameters){
    cleanScrollArea();

    /*
     * Poner el valor de cada uno de los parámetros en los headers de los modelos.
     *
     * !!! Creo que hay un problema con estás últimas dos, no hay forma de ligar los custom sliders con el simulationModel correspondiente.
     * Que la clase custom slider tenga un id el cual será igual al index que lo creo.
     * Hacer un emit para refrescar los nuevos valores del custom slider en el simulationModel correspondiente.
     */

    // Recordar quitar el + 12 en el for y la línea de abajo.
    ModelParameter *modelParameters = new ModelParameter("K", 2.30, 10.00, 0.00);

    for(int index = 0; index < (int) parameters.size() + 12; index++){
        CustomSlider *newCustomSlider = new CustomSlider(this, modelParameters);
        newCustomSlider->setAttribute(Qt::WA_DeleteOnClose);
        this->ui->ScrollLayout->addWidget(newCustomSlider);
        this->parametersSliders.push_back(newCustomSlider);
    }
}

void ModelsCell::setIndex(int index){
    this->index = index;
}

int ModelsCell::getIndex(){
    return this->index;
}

