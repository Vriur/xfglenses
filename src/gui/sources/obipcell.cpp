#include "../headers/obipcell.h"
#include "ui_obipcell.h"

OBIPCell::OBIPCell(QWidget *parent, pair<double, double> *image, int index)
    : QDialog(parent)
    , ui(new Ui::OBIPCell)
{
    ui->setupUi(this);

    this->ui->XSpBox->setValue(image->first);
    this->ui->YSpBox->setValue(image->second);
    this->index = index;
}

OBIPCell::~OBIPCell()
{
    delete ui;
}

void OBIPCell::setIndex(int index){
    this->index = index;
}

int OBIPCell::getIndex(){
    return this->index;
}

void OBIPCell::on_XSpBox_valueChanged(double arg1)
{
    emit this->updateX(arg1, this->index);
}


void OBIPCell::on_YSpBox_valueChanged(double arg1)
{
    emit this->updateY(arg1, this->index);
}


void OBIPCell::on_DeleteBtn_clicked()
{
    emit this->deleteThisCell(this->index);
}
