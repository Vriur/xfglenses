#ifndef BARKANAMODEL_H
#define BARKANAMODEL_H

#include "model.h"

class BarkanaModel : public Model
{
public:
    BarkanaModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // BARKANAMODEL_H
