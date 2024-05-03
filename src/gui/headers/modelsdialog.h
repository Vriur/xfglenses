#ifndef MODELSDIALOG_H
#define MODELSDIALOG_H

#include <QDialog>
#include <QVBoxLayout>

namespace Ui {
class ModelsDialog;
}

class ModelsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModelsDialog(QWidget *parent = nullptr);
    ~ModelsDialog();

private slots:
    void on_AddBtn_clicked();

    void on_DoneBtn_clicked();

private:
    Ui::ModelsDialog *ui;
};

#endif // MODELSDIALOG_H
