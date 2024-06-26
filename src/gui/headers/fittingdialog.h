#ifndef FITTINGDIALOG_H
#define FITTINGDIALOG_H

#include <QDialog>

namespace Ui {
class FittingDialog;
}

class FittingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FittingDialog(QWidget *parent = nullptr);
    ~FittingDialog();

private slots:
    void on_DoneBtn_clicked();

private:
    Ui::FittingDialog *ui;
};

#endif // FITTINGDIALOG_H
