#include "../headers/multipolemodel.h"

MultipoleModel::MultipoleModel(){
    this->setName("Multipole Model");

    this->parameters.push_back(new ModelParameter("E", 1.00, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Theta", 0.00, 0.00, 360.00));
    this->parameters.push_back(new ModelParameter("Gamma", 0.05, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Sigma", 0.05, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Phi", 0.00, 0.00, 360.00));
    this->parameters.push_back(new ModelParameter("R", 0.10, 0.00, 2.00));
    this->parameters.push_back(new ModelParameter("pd", 0.00, 0.00, 10.00));
    this->parameters.push_back(new ModelParameter("k0", 1.00, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Dx", 0.50, -1.00, 1.00));
    this->parameters.push_back(new ModelParameter("Dy", 0.50, -1.00, 1.00));
    this->parameters.push_back(new ModelParameter("Qxx", 0.10, -1.00, 1.00));
    this->parameters.push_back(new ModelParameter("Qxy", 0.00, -1.00, 1.00));
    this->parameters.push_back(new ModelParameter("Qyy", -0.10, -1.00, 1.00));
}
