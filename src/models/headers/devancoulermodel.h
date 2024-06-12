#ifndef DEVANCOULERMODEL_H
#define DEVANCOULERMODEL_H

#include "model.h"

class DeVancoulerModel : public Model
{
public:
    DeVancoulerModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // DEVANCOULERMODEL_H
