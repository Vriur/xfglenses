#include "../headers/nismodel.h"

NISModel::NISModel(){
    this->setName("NIS");

    this->parameters.push_back(new ModelParameter("Theta", 0.00, 0.00, 360.00));
    this->parameters.push_back(new ModelParameter("Gamma", 0.05, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Sigma", 0.05, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Phi", 0.00, 0.00, 360.00));
    this->parameters.push_back(new ModelParameter("R", 0.10, 0.00, 2.00));
    this->parameters.push_back(new ModelParameter("pd", 0.00, 0.00, 10.00));
    this->parameters.push_back(new ModelParameter("Kappa", 1.00, 0.00, 10.00));
    this->parameters.push_back(new ModelParameter("C", 1.00, 0.00, 4.00));
}

double NISModel::jacobian(double x, double y){
    double s2 = 0.00;
    double detJ = 0.00;
    double xbar0 = 0.00;
    double xbar1 = 0.00;
    double jbh11 = 0.00;
    double jbh12 = 0.00;
    double jbh21 = 0.00;
    double jbh22 = 0.00;
    double radiusE2 = 0.00;
    double radiusE4 = 0.00;
    double xc  = this->getParameter("C")->getCurrentValue();

    double j11 = A1;
    double j12 = D;
    double j21 = D;
    double j22 = A2;

    double theta = this->getParameter("Theta")->getCurrentValue();
    double cs = cos((M_PI * theta) / 180.0);
    double ss = sin((M_PI * theta) / 180.0);

    xbar0 =   x * cs + y * ss;
    xbar1 = - x * ss + y * cs;

    radiusE2 = (pow(xbar0, 2) + pow(xbar1, 2));
    radiusE4 = pow(radiusE2, 2);

    double kappa = this->getParameter("Kappa")->getCurrentValue();
    s2 = pow(xc, 2) + radiusE2;
    j11 -= kappa * ((pow(xbar0, 2) - pow(xbar1, 2)) * xc * (1.0 - xc / sqrt(s2)) / radiusE4 + pow(xbar1, 2) / (radiusE2 * sqrt(s2)));
    j12 -= kappa * (xbar0 * xbar1 * (2.0 * xc / radiusE4 - 1.0 / (radiusE2 * sqrt(s2)) - 2.0 * pow(xc, 2) / (radiusE4 * sqrt(s2))));
    j21  = j12;
    j22 -= kappa * ((pow(xbar1, 2) - pow(xbar0, 2)) * xc * (1.0 - xc / sqrt(s2)) / radiusE4 + pow(xbar0, 2) / (radiusE2 * sqrt(s2)));

    // Nuevo
    double funcnis = sqrt(s2) - xc;
    j11 -= kappa * (funcnis/ radiusE2 + (2 * xc * funcnis - radiusE2) / (radiusE4 * sqrt(radiusE2 + pow(xc, 2))) * pow(xbar0, 2));
    j12 -= kappa * ((2 * xc * funcnis - radiusE2) / (radiusE4 * sqrt(radiusE2 + pow(xc, 2))) * xbar0 * xbar1);
    j21 = j12;
    j22 -= kappa * (funcnis/ radiusE2 + (2 * xc * funcnis - radiusE2) / (radiusE4 * sqrt(radiusE2 + pow(xc, 2))) * pow(xbar1, 2));
    //

    /*if(blackHole == 1) {
        jbh11 -= (pow(xbar1, 2) - pow(xbar0, 2)) / radiusE4;
        jbh12 += (2.0 * xbar0 * xbar1) / radiusE4;
        jbh21  = j12;
        jbh22 -= (pow(xbar0, 2) - pow(xbar1, 2)) / radiusE4;
    }*/

    detJ = j11 * j22 - j12 * j21 + jbh11 * jbh22 - jbh12 * jbh21;

    return detJ;
}

void NISModel::setAlphas(double x1, double x2){
    double xc = this->getParameter("C")->getCurrentValue();
    double rE2 = pow(x1, 2) + pow(x2, 2);
    double s2 = pow(xc, 2) + rE2;

    double func = sqrt(s2) - xc;

    double kappa = this->getParameter("Kappa")->getCurrentValue();
    alpha1 = (kappa * func * x1) / rE2;
    alpha2 = (kappa * func * x2) / rE2;
}
