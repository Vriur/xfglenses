#ifndef ELLIPTICPLUMMERMODEL_H
#define ELLIPTICPLUMMERMODEL_H

#include "model.h"

class EllipticPlummerModel : public Model
{
public:
    EllipticPlummerModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // ELLIPTICPLUMMERMODEL_H
