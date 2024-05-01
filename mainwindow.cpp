#include "mainwindow.h"
#include "ui_mainwindow.h"

using std::vector;

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

void MainWindow::on_modelsBtn_clicked()
{
    this->modelsDialog = new ModelsDialog(this);
    this->modelsDialog->show();
    this->hide();
}

