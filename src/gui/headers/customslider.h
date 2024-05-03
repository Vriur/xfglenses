#ifndef CUSTOMSLIDER_H
#define CUSTOMSLIDER_H

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
    explicit CustomSlider(QWidget *parent = nullptr, const string &name = "", const vector<double> &sliderParams = vector<double>());
    ~CustomSlider();
    void setName(string name);
    string getName();
    void setCurrentValue(double currentValue);
    double getCurrentValue();
    int mapDoubleToInt(double currentValue);
    double mapIntToDouble(int currentValue);

private slots:
    void updateLabel(int currentValue);

private:
    Ui::CustomSlider *ui;
    string name;
    double maxValue;
    double minValue;
    double initialValue;
    double currentValue;
};

#endif // CUSTOMSLIDER_H
