#include "../headers/truncatedkingmodel.h"

TruncatedKingModel::TruncatedKingModel(){
    this->setName("Truncated King");

    this->parameters.push_back(new ModelParameter("E", 1.00, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Theta", 0.00, 0.00, 360.00));
    this->parameters.push_back(new ModelParameter("Gamma", 0.05, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Sigma", 0.05, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Phi", 0.00, 0.00, 360.00));
    this->parameters.push_back(new ModelParameter("R", 0.10, 0.00, 2.00));
    this->parameters.push_back(new ModelParameter("pd", 0.00, 0.00, 10.00));
    this->parameters.push_back(new ModelParameter("xt", 5.00, 0.00, 15.00));
    this->parameters.push_back(new ModelParameter("C", 1.00, 0.00, 4.00));
}
