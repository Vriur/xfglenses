#ifndef TRUNCATEDKINGMODEL_H
#define TRUNCATEDKINGMODEL_H

#include "model.h"

class TruncatedKingModel : public Model
{
public:
    TruncatedKingModel();
    double jacobian(double x, double y) override;
    void setAlphas(double x1, double x2) override;
};

#endif // TRUNCATEDKINGMODEL_H
