#ifndef TRANSPARENTSPHEREMODEL_H
#define TRANSPARENTSPHEREMODEL_H

#include "model.h"

class TransparentSphereModel : public Model
{
public:
    TransparentSphereModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // TRANSPARENTSPHEREMODEL_H
