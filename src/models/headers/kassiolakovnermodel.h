#ifndef KASSIOLAKOVNERMODEL_H
#define KASSIOLAKOVNERMODEL_H

#include "model.h"

class KassiolaKovnerModel : public Model
{
public:
    KassiolaKovnerModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // KASSIOLAKOVNERMODEL_H
