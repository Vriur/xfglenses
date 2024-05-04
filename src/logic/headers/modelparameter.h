#ifndef MODELPARAMETER_H
#define MODELPARAMETER_H

class ModelParameter
{
public:
    ModelParameter(string name, double currentValue, double maxValue, double minValue);
    ~ModelParameter();
    void setName(string name);
    void setCurrentValue(double currentValue);
    void setMaxValue(double maxValue);
    void setMinValue(double minValue);
    string getName();
    double getCurrentValue();
    double getMaxValue();
    double getMinValue();


private:
    string name;
    double currentValue;
    double maxValue;
    double minValue;
};

#endif // MODELPARAMETER_H
