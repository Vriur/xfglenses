#ifndef UNIFORMRINGMODEL_H
#define UNIFORMRINGMODEL_H

#include "model.h"

class UniformRingModel : public Model
{
public:
    UniformRingModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // UNIFORMRINGMODEL_H
