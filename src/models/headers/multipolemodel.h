#ifndef MULTIPOLEMODEL_H
#define MULTIPOLEMODEL_H

#include "model.h"

class MultipoleModel : public Model
{
public:
    MultipoleModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // MULTIPOLEMODEL_H
