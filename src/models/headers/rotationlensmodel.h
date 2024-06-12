#ifndef ROTATIONLENSMODEL_H
#define ROTATIONLENSMODEL_H

#include "model.h"

class RotationLensModel : public Model
{
public:
    RotationLensModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // ROTATIONLENSMODEL_H
