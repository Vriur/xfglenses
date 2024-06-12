#ifndef ELLIPTICMODEL_H
#define ELLIPTICMODEL_H

#include "model.h"

class EllipticModel : public Model
{
public:
    EllipticModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // ELLIPTICMODEL_H
