#ifndef HUBBLEMODEL_H
#define HUBBLEMODEL_H

#include "model.h"

class HubbleModel : public Model
{
public:
    HubbleModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // HUBBLEMODEL_H
