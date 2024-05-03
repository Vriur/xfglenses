#ifndef MODELSOPTION_H
#define MODELSOPTION_H

#include <QDialog>
#include <QHBoxLayout>

namespace Ui {
class ModelsOption;
}

class ModelsOption : public QDialog
{
    Q_OBJECT

public:
    explicit ModelsOption(QWidget *parent = nullptr);
    ~ModelsOption();
    void cleanScrollArea();

private slots:
    void on_ModelMenuCmBox_currentTextChanged(const QString &arg1);

private:
    Ui::ModelsOption *ui;
};

#endif // MODELSOPTION_H
