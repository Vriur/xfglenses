#ifndef KINGMODEL_H
#define KINGMODEL_H

#include "model.h"

class KingModel : public Model
{
public:
    KingModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // KINGMODEL_H
