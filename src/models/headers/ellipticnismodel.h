#ifndef ELLIPTICNISMODEL_H
#define ELLIPTICNISMODEL_H

#include "model.h"

class EllipticNISModel : public Model
{
public:
    EllipticNISModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // ELLIPTICNISMODEL_H
