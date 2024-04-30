#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customslider.h"

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

void MainWindow::on_ModelMenuCmBox_currentTextChanged(const QString &arg1)
{
    CustomSlider *instance = new CustomSlider(this);
    ui->horizontalLayout_4->addWidget(instance);
}

