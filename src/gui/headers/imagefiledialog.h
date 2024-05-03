#ifndef IMAGEFILEDIALOG_H
#define IMAGEFILEDIALOG_H

#include <QDialog>

namespace Ui {
class ImageFileDialog;
}

class ImageFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageFileDialog(QWidget *parent = nullptr);
    ~ImageFileDialog();

private:
    Ui::ImageFileDialog *ui;
};

#endif // IMAGEFILEDIALOG_H
