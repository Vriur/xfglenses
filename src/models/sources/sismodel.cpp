#include "../headers/sismodel.h"

SISModel::SISModel(){
    this->setName("SIS");

    this->parameters.push_back(new ModelParameter("Theta", 0.00, 0.00, 360.00));
    this->parameters.push_back(new ModelParameter("Gamma", 0.05, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Sigma", 0.05, 0.00, 4.00));
    this->parameters.push_back(new ModelParameter("Phi", 0.00, 0.00, 360.00));
    this->parameters.push_back(new ModelParameter("R", 0.10, 0.00, 2.00));
    this->parameters.push_back(new ModelParameter("pd", 0.00, 0.00, 10.00));
    this->parameters.push_back(new ModelParameter("Alpha", 1.00, 0.00, 3.00));
}

double SISModel::jacobian(double x, double y){
    double rbeta = 0.00;
    double detJ = 0.00;
    double xbar0 = 0.00;
    double xbar1 = 0.00;
    double jbh11 = 0.00;
    double jbh12 = 0.00;
    double jbh21 = 0.00;
    double jbh22 = 0.00;
    double radiusE = 0.00;
    double radiusE2 = 0.00;

    double j11 = this->getA1();
    double j12 = this->getD();
    double j21 = this->getD();
    double j22 = this->getA2();

    double theta = this->getParameter("Theta")->getCurrentValue();
    double cs = cos((M_PI * theta) / 180.0);
    double ss = sin((M_PI * theta) / 180.0);

    xbar0 =   x * cs + y * ss;
    xbar1 = - x * ss + y * cs;

    radiusE2 = pow(xbar0, 2) + pow(xbar1, 2);
    radiusE  = sqrt(radiusE2);

    double alpha = this->getParameter("Alpha")->getCurrentValue();
    rbeta = pow(radiusE, (alpha - 3.0));
    j11 -= rbeta * (pow(xbar1, 2) + alpha * pow(xbar0, 2));
    j12 -= rbeta * (alpha - 1.0) * xbar0 * xbar1;
    j21  = j12;
    j22 -= rbeta * (pow(xbar0, 2) + alpha * pow(xbar1, 2));

    /*
        double radiusE4 = 0.00;
        radiusE4 = pow(radiusE2, 2);
        if(blackHole == true) {
            jbh11 -= (pow(xbar1, 2) - pow(xbar0, 2)) / radiusE4;
            jbh12 += (2.0 * xbar0 * xbar1) / radiusE4;
            jbh21  = j12;
            jbh22 -= (pow(xbar0, 2) - pow(xbar1, 2)) / radiusE4;
        }
    */

    detJ = j11 * j22 - j12 * j21 + jbh11 * jbh22 - jbh12 * jbh21;

    return detJ;
}

void SISModel::setAlphas(double x1, double x2){
    double rE  = sqrt(pow(x1, 2) + pow(x2, 2));
    double rbeta = pow(rE, (this->getParameter("Alpha")->getCurrentValue() - 1.0));

    alpha1 = rbeta * x1;
    alpha2 = rbeta * x2;
}
