#include "src/gui/headers/mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->ContourChkBtn->setChecked(this->simulationParameters.getShowInGraph("Contour"));
    this->ui->GridChkBtn->setChecked(this->simulationParameters.getShowInGraph("Grid"));
    this->ui->ImagesChkBtn->setChecked(this->simulationParameters.getShowInGraph("Images"));
    this->ui->InversionChkBtn->setChecked(this->simulationParameters.getShowInGraph("Inversion"));
    this->ui->RayPlotChkBtn->setChecked(this->simulationParameters.getShowInGraph("RayPlot"));
    this->ui->RootsChkBtn->setChecked(this->simulationParameters.getShowInGraph("Roots"));
    this->ui->R_EChkBtn->setChecked(this->simulationParameters.getShowInGraph("R_E"));
    this->ui->SourceChkBtn->setChecked(this->simulationParameters.getShowInGraph("Source"));
    this->ui->TimeDelayChkBtn->setChecked(this->simulationParameters.getShowInGraph("TimeDelay"));

    this->ui->XSpBox->setValue(this->simulationParameters.getSourcePosition().first);
    this->ui->YSpBox->setValue(this->simulationParameters.getSourcePosition().second);

    this->ui->SourceMenuCmBox->setCurrentText(QString::fromStdString(this->simulationParameters.getSourceType()));

    connect(this->ui->sourceGraph, SIGNAL(updateSourceCoordinates(double, double)), this, SLOT(updateSourceCoordinates(double, double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CausticBtn_clicked()
{
    this->causticDialog = new CausticDialog(this, this->simulationParameters);
    this->causticDialog->show();
}

void MainWindow::on_FittingBtn_clicked()
{
    this->fittingDialog = new FittingDialog(this);
    this->fittingDialog->show();
}

void MainWindow::on_HelpBtn_clicked()
{
    this->helpDialog = new HelpDialog(this);
    this->helpDialog->show();
}

void MainWindow::on_ImageFileBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "File to load", "./", tr("Images (*.png *.jpeg *.jpg)"));
    this->simulationParameters.setImageFilePath(fileName.toStdString());
}

void MainWindow::on_LightCurveBtn_clicked()
{
    this->lightCurveDialog = new LightCurveDialog(this);
    this->lightCurveDialog->show();
}

void MainWindow::on_ModelsBtn_clicked()
{
    this->modelsDialog = new ModelsDialog(this, simulationModels);
    this->modelsDialog->show();
}

void MainWindow::on_OBIPBtn_clicked()
{
    this->obipDialog = new OBIPDialog(this, this->simulationParameters);
    this->obipDialog->show();
}

void MainWindow::on_TrackBtn_clicked()
{
    this->trackDialog = new TrackDialog(this, this->simulationParameters);

    connect(this->trackDialog, SIGNAL(startAnimation(QTimeLine *, double, double, double, double)), this, SLOT(startAnimation(QTimeLine *, double, double, double, double)));

    this->trackDialog->show();
}

void MainWindow::on_SimulationBtn_clicked()
{
    this->simulationDialog = new SimulationDialog(this, this->simulationModels, this->simulationParameters);
    this->simulationDialog->show();
}

void MainWindow::on_PrintBtn_clicked()
{
    // El botón print guarda en data sin preguntar, es decir, no hay vista previa.
}

void MainWindow::on_SourceChkBtn_stateChanged(int arg1)
{
    this->simulationParameters.setShowInGraph("Source", (bool) arg1);
}

void MainWindow::on_ImagesChkBtn_stateChanged(int arg1)
{
    this->simulationParameters.setShowInGraph("Images", (bool) arg1);
}

void MainWindow::on_GridChkBtn_stateChanged(int arg1)
{
    this->simulationParameters.setShowInGraph("Grid", (bool) arg1);
}

void MainWindow::on_RayPlotChkBtn_stateChanged(int arg1)
{
    this->simulationParameters.setShowInGraph("RayPlot", (bool) arg1);
}

void MainWindow::on_RootsChkBtn_stateChanged(int arg1)
{
    this->simulationParameters.setShowInGraph("Roots", (bool) arg1);
}

void MainWindow::on_R_EChkBtn_stateChanged(int arg1)
{
    this->simulationParameters.setShowInGraph("R_E", (bool) arg1);
}

void MainWindow::on_ContourChkBtn_stateChanged(int arg1)
{
    this->simulationParameters.setShowInGraph("Contour", (bool) arg1);
}

void MainWindow::on_InversionChkBtn_stateChanged(int arg1)
{
    this->simulationParameters.setShowInGraph("Inversion", (bool) arg1);
}

void MainWindow::on_TimeDelayChkBtn_stateChanged(int arg1)
{
    this->simulationParameters.setShowInGraph("TimeDelay", (bool) arg1);
}

void MainWindow::on_XSpBox_valueChanged(double arg1)
{
    this->simulationParameters.setSourcePositionX(arg1);
    this->ui->sourceGraph->updateSourceXCoordinate(arg1);
}

void MainWindow::on_YSpBox_valueChanged(double arg1)
{
    this->simulationParameters.setSourcePositionY(arg1);
    this->ui->sourceGraph->updateSourceYCoordinate(arg1);
}

void MainWindow::on_SourceMenuCmBox_currentTextChanged(const QString &arg1)
{
    this->simulationParameters.setSourceType(arg1.toStdString());
}

void MainWindow::startAnimation(QTimeLine *timer, double initialX, double initialY, double finalX, double finalY){
    this->ui->sourceGraph->trackAnimation(timer, initialX, initialY, finalX, finalY);
}

void MainWindow::updateSourceCoordinates(double x, double y){
    this->ui->XSpBox->setValue(x);
    this->ui->YSpBox->setValue(y);
}
