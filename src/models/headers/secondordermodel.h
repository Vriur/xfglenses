#ifndef SECONDORDERMODEL_H
#define SECONDORDERMODEL_H

#include "model.h"

class SecondOrderModel : public Model
{
public:
    SecondOrderModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // SECONDORDERMODEL_H
