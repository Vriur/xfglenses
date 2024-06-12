#include "../headers/nfwmodel.h"

NFWModel::NFWModel(){
    this->setName("NFW");

    this->parameters.push_back(new ModelParameter("Theta", 0.00, 0.00, 360.00));
    this->parameters.push_back(new ModelParameter("Gamma", 0.05, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Sigma", 0.05, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Phi", 0.00, 0.00, 360.00));
    this->parameters.push_back(new ModelParameter("R", 0.10, 0.00, 2.00));
    this->parameters.push_back(new ModelParameter("pd", 0.00, 0.00, 10.00));
    this->parameters.push_back(new ModelParameter("k", 1.00, 0.00, 10.00));
}

double NFWModel::jacobian(double x, double y){
    return x+ y;
}

void NFWModel::setAlphas(double x1, double x2){
    alpha1 = x1 + x2;
}
