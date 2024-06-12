#ifndef NISMODEL_H
#define NISMODEL_H

#include "model.h"

class NISModel : public Model
{
public:
    NISModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // NISMODEL_H
