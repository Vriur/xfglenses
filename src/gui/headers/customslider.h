#ifndef CUSTOMSLIDER_H
#define CUSTOMSLIDER_H

#include "src/models/headers/modelparameter.h"

#include <QWidget>

using std::string;
using std::vector;

namespace Ui {
class CustomSlider;
}

class CustomSlider : public QWidget
{
    Q_OBJECT

public:
    explicit CustomSlider(QWidget *parent = nullptr, ModelParameter* parameter = nullptr);
    ~CustomSlider();
    void setName(string name);
    string getName();
    void setCurrentValue(double currentValue);
    double getCurrentValue();
    void setMinValue(double minValue);
    double getMinValue();
    void setMaxValue(double maxValue);
    double getMaxValue();

signals:
    void updateParameterValue(double value);

private slots:
    void updateLabel(int currentValue);

    void on_Slider_valueChanged(int value);

private:
    Ui::CustomSlider *ui;
    string name;
    double maxValue;
    double minValue;
    double currentValue;
};

#endif // CUSTOMSLIDER_H
