#include "src/gui/headers/causticdialog.h"
#include "ui_causticdialog.h"

CausticDialog::CausticDialog(QWidget *parent, SimulationParameters &simulationParameters)
    : QDialog(parent)
    , ui(new Ui::CausticDialog)
{
    ui->setupUi(this);

    this->ui->DXSpnBox->setValue(simulationParameters.getCausticDX());
    this->ui->TOLSpnBox->setValue(simulationParameters.getCausticTOL());

    this->ui->CriticalCurvesChkBox->setChecked(simulationParameters.getShowInGraph("CriticalCurves"));
    this->ui->CausticsChkBox->setChecked(simulationParameters.getShowInGraph("Caustics"));

    connect(this, SIGNAL(updateDoubleValue(double)), &simulationParameters, SLOT(setCausticDX(double)));
    connect(this, SIGNAL(updateDoubleValue(double)), &simulationParameters, SLOT(setCausticTOL(double)));
    connect(this, SIGNAL(updateBoolValue(string, bool)), &simulationParameters, SLOT(setShowInGraph(string,bool)));
    connect(this, SIGNAL(updateBoolValue(string, bool)), &simulationParameters, SLOT(setShowInGraph(string,bool)));
}

CausticDialog::~CausticDialog()
{
    delete ui;
}

void CausticDialog::on_DoneBtn_clicked()
{
    this->close();
}


void CausticDialog::on_DXSpnBox_valueChanged(double arg1)
{
    emit this->updateDoubleValue(arg1);
}


void CausticDialog::on_TOLSpnBox_valueChanged(double arg1)
{
    emit this->updateDoubleValue(arg1);
}


void CausticDialog::on_CriticalCurvesChkBox_stateChanged(int arg1)
{
    emit this->updateBoolValue("CriticalCurves", (bool) arg1);
}


void CausticDialog::on_CausticsChkBox_stateChanged(int arg1)
{
    emit this->updateBoolValue("CriticalCurves", (bool) arg1);
}

