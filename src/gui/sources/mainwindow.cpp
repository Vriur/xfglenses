#include "src/gui/headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CausticBtn_clicked()
{
    this->causticDialog = new CausticDialog(this);
    this->causticDialog->show();
    //this->hide();
}

void MainWindow::on_FittingBtn_clicked()
{
    this->fittingDialog = new FittingDialog(this);
    this->fittingDialog->show();
    //this->hide();
}

void MainWindow::on_HelpBtn_clicked()
{
    this->helpDialog = new HelpDialog(this);
    this->helpDialog->show();
    //this->hide();
}

void MainWindow::on_ImageFileBtn_clicked()
{
    this->imageFileDialog = new ImageFileDialog(this);
    this->imageFileDialog->show();
    //this->hide();
}

void MainWindow::on_LightCurveBtn_clicked()
{
    this->lightCurveDialog = new LightCurveDialog(this);
    this->lightCurveDialog->show();
    //this->hide();
}

void MainWindow::on_ModelsBtn_clicked()
{
    this->modelsDialog = new ModelsDialog(this, simulationModels);
    this->modelsDialog->show();
    //this->hide();
}

void MainWindow::on_OBIPBtn_clicked()
{
    this->obipDialog = new OBIPDialog(this);
    this->obipDialog->show();
    //this->hide();
}

void MainWindow::on_TrackBtn_clicked()
{
    this->trackDialog = new TrackDialog(this);
    this->trackDialog->show();
    //this->hide();
}

void MainWindow::on_PrintBtn_clicked()
{
    // El botón print guarda en data sin preguntar, es decir, no hay vista previa.
}

