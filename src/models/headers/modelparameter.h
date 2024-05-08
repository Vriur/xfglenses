#ifndef MODELPARAMETER_H
#define MODELPARAMETER_H

#include <QObject>
#include <string>

using std::string;

class ModelParameter : public QObject
{
    Q_OBJECT

public:
    ModelParameter(string name, double currentValue, double minValue, double maxValue);
    ~ModelParameter();
    void setName(string name);
    void setMaxValue(double maxValue);
    void setMinValue(double minValue);
    string getName();
    double getCurrentValue();
    double getMaxValue();
    double getMinValue();

public slots:
    void setCurrentValue(double currentValue);

private:
    string name;
    double currentValue;
    double maxValue;
    double minValue;
};

#endif // MODELPARAMETER_H
