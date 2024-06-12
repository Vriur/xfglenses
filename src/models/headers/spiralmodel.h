#ifndef SPIRALMODEL_H
#define SPIRALMODEL_H

#include "model.h"

class SpiralModel : public Model
{
public:
    SpiralModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // SPIRALMODEL_H
