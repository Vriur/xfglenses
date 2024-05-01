#ifndef MODELSDIALOG_H
#define MODELSDIALOG_H

#include <QDialog>

namespace Ui {
class ModelsDialog;
}

class ModelsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModelsDialog(QWidget *parent = nullptr);
    ~ModelsDialog();

private:
    Ui::ModelsDialog *ui;
};

#endif // MODELSDIALOG_H
