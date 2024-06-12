#ifndef SISMODEL_H
#define SISMODEL_H

#include "model.h"

class SISModel : public Model
{
public:
    SISModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // SISMODEL_H
