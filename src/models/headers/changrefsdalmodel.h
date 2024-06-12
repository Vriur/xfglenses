#ifndef CHANGREFSDALMODEL_H
#define CHANGREFSDALMODEL_H

#include "model.h"

class ChangRefsdalModel : public Model
{
public:
    ChangRefsdalModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // CHANGREFSDALMODEL_H
