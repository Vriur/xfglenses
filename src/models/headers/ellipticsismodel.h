#ifndef ELLIPTICSISMODEL_H
#define ELLIPTICSISMODEL_H

#include "model.h"

class EllipticSISModel : public Model
{
public:
    EllipticSISModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // ELLIPTICSISMODEL_H
