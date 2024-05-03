#include "src/gui/headers/modelsdialog.h"
#include "ui_modelsdialog.h"

#include "src/gui/headers/modelsoption.h"

ModelsDialog::ModelsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModelsDialog)
{
    ui->setupUi(this);
    this->showMaximized();
}

ModelsDialog::~ModelsDialog()
{
    delete ui;
}

void ModelsDialog::on_AddBtn_clicked()
{
    ModelsOption *newModel = new ModelsOption(this);
    this->ui->ScrollLayout->addWidget(newModel);
}

void ModelsDialog::on_DoneBtn_clicked()
{
    this->hide();
}

