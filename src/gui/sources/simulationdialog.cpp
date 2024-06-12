#include "../headers/simulationdialog.h"
#include "ui_simulationdialog.h"

#include <QDebug>

SimulationDialog::SimulationDialog(QWidget *parent, vector<Model*> &simulationModels, SimulationParameters &simulationParameters)
    : QDialog(parent)
    , ui(new Ui::SimulationDialog)
{
    ui->setupUi(this);

    this->simulationModels = &simulationModels;
    this->simulationParameters = &simulationParameters;

    this->blackHole = true;

    this->ui->plot->xAxis->setRange(-4, 4);
    this->ui->plot->yAxis->setRange(-4, 4);
    this->ui->plot->replot();

    if(!this->simulationModels->empty()){
        this->images(this->simulationModels->at(0));
        this->critical(this->simulationModels->at(0));
        this->caustic(this->simulationModels->at(0));
    }
}

SimulationDialog::~SimulationDialog()
{
    delete ui;
}

void SimulationDialog::images(Model *model){
    double x1bar = 0.00;
    double x2bar = 0.00;
    double dist2 = 0.00;

    double y1 = 0.00;
    double y2 = 0.00;
    double z1 = this->simulationParameters->getSourcePosition().first;
    double z2 = this->simulationParameters->getSourcePosition().second;

    double theta = model->getParameter("Theta")->getCurrentValue();
    double cs = cos((M_PI * theta) / 180.0);
    double ss = sin((M_PI * theta) / 180.0);

    for(int x1 = - LIMIT; x1 <= LIMIT; ++x1) {
        for(int x2 = - LIMIT; x2 <= LIMIT; ++x2) {
            x1bar = (x1 * CONVERTIONFACTOR) * cs + (x2 * CONVERTIONFACTOR) * ss;
            x2bar = - (x1 * CONVERTIONFACTOR) * ss + (x2 * CONVERTIONFACTOR) * cs;

            lensEquation(model, x1bar, x2bar, &y1, &y2);

            dist2 = pow((y1 - z1), 2) + pow((y2 - z2), 2);

            if(dist2 <= pow(model->getParameter("R")->getCurrentValue(), 2)) {
                this->imagesX.append((y1 * CONVERTIONFACTOR) - z1);
                this->imagesY.append((y2 * CONVERTIONFACTOR) - z2);
            }
        }
    }
}

void SimulationDialog::caustic(Model *model){
    double y1cr = 0.00;
    double y2cr = 0.00;

    double phi = model->getParameter("Phi")->getCurrentValue();
    double d0 = (M_PI * phi) / 180.0;

    double gamma = model->getParameter("Gamma")->getCurrentValue();
    double sigma = model->getParameter("Sigma")->getCurrentValue();
    model->setA1(1.0 - sigma - gamma * cos(2.0 * d0));
    model->setA2(1.0 - sigma + gamma * cos(2.0 * d0));
    model->setD(- gamma * sin(2.0 * d0));

    y1Caustic.clear();
    y2Caustic.clear();

    for(int iterator = 0; iterator < x1Caustic.length(); ++iterator){
        y1cr = model->getA1() * x1Caustic[iterator] + model->getD() * x2Caustic[iterator];
        y2cr = model->getA2() * x2Caustic[iterator] + model->getD() * x1Caustic[iterator];

        this->y1Caustic.append(y1cr - model->getAlpha1());
        this->y2Caustic.append(y2cr - model->getAlpha2());

        /* Magenta */
        //draw_point(x1_caustic[i], x2_caustic[i], 1.0, 6);

        /* Black */
        //draw_point(y1_caustic[i], y2_caustic[i], 1.0, 7);
    }
    qDebug() << x1Caustic.length() << " " << x2Caustic.length() << " " <<  y1Caustic.length() << " " << y2Caustic.length();
}

void SimulationDialog::critical(Model *model){
    x1Caustic.clear();
    x2Caustic.clear();

    for(int xCritic = - LIMIT; xCritic <= LIMIT; ++xCritic){
        for(int yCritic = - LIMIT; yCritic <= LIMIT; ++yCritic){
            if(fabs(model->jacobian(xCritic, yCritic)) <= this->simulationParameters->getCausticTOL()) {
                this->x1Caustic.append(xCritic);
                this->x2Caustic.append(yCritic);
            }
        }
    }
}

void SimulationDialog::lensEquation(Model *model, double x1, double x2, double *y1, double *y2){
    double alphaX = 0.00;
    double alphaY = 0.00;
    double dist1 = 0.00;    // = parms[P_X_1];
    double dist2 = 0.00;    // = parms[P_Y_1];
    double bhBeta = 0.01;   // = parms[P_ALPHA2];

    double phi = model->getParameter("Phi")->getCurrentValue();
    double d0 = (M_PI * phi) / 180.0;

    double gamma = model->getParameter("Gamma")->getCurrentValue();
    double sigma = model->getParameter("Sigma")->getCurrentValue();
    model->setA1(1.0 - sigma - gamma * cos(2.0 * d0));
    model->setA2(1.0 - sigma + gamma * cos(2.0 * d0));
    model->setD(- gamma * sin(2.0 * d0));

    if(blackHole == true) {
        double sdist2 = pow((x1 - dist1), 2) + pow((x2 - dist2), 2);

        alphaX = (bhBeta * (x1 - dist1)) / sdist2;
        alphaY = (bhBeta * (x2 - dist2)) / sdist2;
    }

    double yeq1 = model->getA1() * x1 + model->getD() * x2 - alphaX;
    double yeq2 = model->getA2() * x2 + model->getD() * x1 - alphaY;

    *y1 = yeq1 - model->getAlpha1();
    *y2 = yeq2 - model->getAlpha2();
}
