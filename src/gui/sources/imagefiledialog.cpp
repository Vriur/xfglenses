#include "src/gui/headers/imagefiledialog.h"
#include "ui_imagefiledialog.h"

ImageFileDialog::ImageFileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ImageFileDialog)
{
    ui->setupUi(this);
}

ImageFileDialog::~ImageFileDialog()
{
    delete ui;
}
