#ifndef NFWMODEL_H
#define NFWMODEL_H

#include "model.h"

class NFWModel : public Model
{
public:
    NFWModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // NFWMODEL_H
