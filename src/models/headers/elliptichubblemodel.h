#ifndef ELLIPTICHUBBLEMODEL_H
#define ELLIPTICHUBBLEMODEL_H

#include "model.h"

class EllipticHubbleModel : public Model
{
public:
    EllipticHubbleModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // ELLIPTICHUBBLEMODEL_H
