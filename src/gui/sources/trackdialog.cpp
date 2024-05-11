#include "src/gui/headers/trackdialog.h"
#include "ui_trackdialog.h"

#include <QDebug>

TrackDialog::TrackDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TrackDialog)
{
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowFullscreenButtonHint | Qt::WindowMaximizeButtonHint);
    ui->setupUi(this);

    this->ui->InitialX->setName("Ax");
    this->ui->InitialX->setCurrentValue((double) 0.00);
    this->ui->InitialX->setMinValue((double) -4.00);
    this->ui->InitialX->setMaxValue((double) 4.00);

    this->ui->InitialY->setName("Ay");
    this->ui->InitialY->setCurrentValue((double) 0.00);
    this->ui->InitialY->setMinValue((double) -4.00);
    this->ui->InitialY->setMaxValue((double) 4.00);

    this->ui->FinalX->setName("Bx");
    this->ui->FinalX->setCurrentValue((double) 0.00);
    this->ui->FinalX->setMinValue((double) -4.00);
    this->ui->FinalX->setMaxValue((double) 4.00);

    this->ui->FinalY->setName("By");
    this->ui->FinalY->setCurrentValue((double) 0.00);
    this->ui->FinalY->setMinValue((double) -4.00);
    this->ui->FinalY->setMaxValue((double) 4.00);

}

TrackDialog::~TrackDialog()
{
    delete ui;
}
