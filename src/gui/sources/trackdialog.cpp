#include "src/gui/headers/trackdialog.h"
#include "ui_trackdialog.h"

TrackDialog::TrackDialog(QWidget *parent, SimulationParameters &simulationParameters)
    : QDialog(parent)
    , ui(new Ui::TrackDialog)
{
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowFullscreenButtonHint | Qt::WindowMaximizeButtonHint);
    ui->setupUi(this);

    this->ui->InitialX->setName("Ax");
    this->ui->InitialX->setMinValue((double) -4.00);
    this->ui->InitialX->setMaxValue((double) 4.00);
    this->ui->InitialX->setCurrentValue((double) simulationParameters.getAnimationSourceInitialPosition().first);

    this->ui->InitialY->setName("Ay");
    this->ui->InitialY->setMinValue((double) -4.00);
    this->ui->InitialY->setMaxValue((double) 4.00);
    this->ui->InitialY->setCurrentValue((double) simulationParameters.getAnimationSourceInitialPosition().second);

    this->ui->FinalX->setName("Bx");
    this->ui->FinalX->setMinValue((double) -4.00);
    this->ui->FinalX->setMaxValue((double) 4.00);
    this->ui->FinalX->setCurrentValue((double) simulationParameters.getAnimationSourceFinalPosition().first);

    this->ui->FinalY->setName("By");
    this->ui->FinalY->setMinValue((double) -4.00);
    this->ui->FinalY->setMaxValue((double) 4.00);
    this->ui->FinalY->setCurrentValue((double) simulationParameters.getAnimationSourceFinalPosition().second);

    connect(this->ui->InitialX, SIGNAL(updateParameterValue(double)), &simulationParameters, SLOT(setAnimationSourceInitialPositionX(double)));
    connect(this->ui->InitialY, SIGNAL(updateParameterValue(double)), &simulationParameters, SLOT(setAnimationSourceInitialPositionY(double)));
    connect(this->ui->FinalX, SIGNAL(updateParameterValue(double)), &simulationParameters, SLOT(setAnimationSourceFinalPositionX(double)));
    connect(this->ui->FinalY, SIGNAL(updateParameterValue(double)), &simulationParameters, SLOT(setAnimationSourceFinalPositionY(double)));
}

TrackDialog::~TrackDialog()
{
    delete ui;
}

void TrackDialog::on_DoneBtn_clicked()
{
    this->close();
}

