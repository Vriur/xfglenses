#include "src/gui/headers/obipdialog.h"
#include "ui_obipdialog.h"

OBIPDialog::OBIPDialog(QWidget *parent, SimulationParameters &simulationParameters)
    : QDialog(parent)
    , ui(new Ui::OBIPDialog)
{
    ui->setupUi(this);

    this->simulationParameters = &simulationParameters;
    this->imagesNum =0;

    for(auto image : simulationParameters.getImages()){
        this->createCell(image);
    }
}

OBIPDialog::~OBIPDialog()
{
    delete ui;
}

void OBIPDialog::on_AddBtn_clicked()
{
    this->createCell();
    this->simulationParameters->createImage();
}

void OBIPDialog::on_DoneBtn_clicked()
{
    this->close();
}

void OBIPDialog::createCell(pair<double, double> *image){
    OBIPCell *newCell = new OBIPCell(this, image, this->imagesNum);
    newCell->setAttribute(Qt::WA_DeleteOnClose);

    this->ui->ScrollLayout->addWidget(newCell);
    this->imagesWidgets.push_back(newCell);
    this->imagesNum++;

    connect(newCell, SIGNAL(deleteThisCell(int)), this, SLOT(deleteCell(int)));
    connect(newCell, SIGNAL(updateX(double, int)), this, SLOT(updateX(double, int)));
    connect(newCell, SIGNAL(updateY(double, int)), this, SLOT(updateY(double, int)));
}

void OBIPDialog::updateX(double x, int index){
    this->simulationParameters->editImageX(x, index);
}

void OBIPDialog::updateY(double y, int index){
    this->simulationParameters->editImageY(y, index);
}

void OBIPDialog::deleteCell(int index){
    for(int i = index + 1; i < (int) imagesWidgets.size(); i++){
        imagesWidgets[i]->setIndex(imagesWidgets[i]->getIndex() - 1);
    }

    this->imagesWidgets[index]->close();
    this->imagesWidgets.erase(std::next(imagesWidgets.begin(), index));
    this->simulationParameters->deleteImage(index);
    this->imagesNum--;
}

void OBIPDialog::on_ClearBtn_clicked()
{
    for(auto imageWidget : imagesWidgets){
        imageWidget->close();
    }

    this->imagesWidgets.clear();
    this->simulationParameters->clearImages();
    this->imagesNum = 0;
}

