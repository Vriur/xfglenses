#ifndef ELLIPTICKINGMODEL_H
#define ELLIPTICKINGMODEL_H

#include "model.h"

class EllipticKingModel : public Model
{
public:
    EllipticKingModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // ELLIPTICKINGMODEL_H
