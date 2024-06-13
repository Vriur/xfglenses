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

    this->ui->plot->xAxis->grid()->setVisible(false);
    this->ui->plot->yAxis->grid()->setVisible(false);

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

    this->imagesX.clear();
    this->imagesY.clear();

    for(int x1 = - LIMIT; x1 <= LIMIT; ++x1) {
        for(int x2 = - LIMIT; x2 <= LIMIT; ++x2) {
            x1bar = (x1 * CONVERTIONFACTOR) * cs + (x2 * CONVERTIONFACTOR) * ss;
            x2bar = - (x1 * CONVERTIONFACTOR) * ss + (x2 * CONVERTIONFACTOR) * cs;

            lensEquation(model, x1bar, x2bar, &y1, &y2);

            dist2 = pow((y1 - z1), 2) + pow((y2 - z2), 2);

            if(dist2 <= pow(model->getParameter("R")->getCurrentValue(), 2)) {
                this->imagesX.append(y1 - z1);
                this->imagesY.append(y2 - z2);
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

    this->y1Caustic.clear();
    this->y2Caustic.clear();

    for(int iterator = 0; iterator < x1Caustic.length(); ++iterator){
        y1cr = model->getA1() * x1Caustic[iterator] + model->getD() * x2Caustic[iterator];
        y2cr = model->getA2() * x2Caustic[iterator] + model->getD() * x1Caustic[iterator];

        model->setAlphas(x1Caustic[iterator], x2Caustic[iterator]);

        this->y1Caustic.append(y1cr - model->getAlpha1());
        this->y2Caustic.append(y2cr - model->getAlpha2());
    }

    QCPScatterStyle scatterCritical;
    scatterCritical.setShape(QCPScatterStyle::ssCircle);
    scatterCritical.setPen(QPen(Qt::magenta));
    scatterCritical.setBrush(Qt::magenta);
    scatterCritical.setSize(1);

    QCPScatterStyle scatterCaustic;
    scatterCaustic.setShape(QCPScatterStyle::ssCircle);
    scatterCaustic.setPen(QPen(Qt::black));
    scatterCaustic.setBrush(Qt::black);
    scatterCaustic.setSize(1);

    QCPScatterStyle scatterImages;
    scatterImages.setShape(QCPScatterStyle::ssCircle);
    scatterImages.setPen(QPen(Qt::black));
    scatterImages.setBrush(Qt::black);
    scatterImages.setSize(1);

    this->ui->plot->addGraph();
    this->ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
    this->ui->plot->graph(0)->setScatterStyle(scatterCritical);
    this->ui->plot->graph(0)->setData(this->x1Caustic, this->x2Caustic);

    this->ui->plot->addGraph();
    this->ui->plot->graph(1)->setLineStyle(QCPGraph::lsNone);
    this->ui->plot->graph(1)->setScatterStyle(scatterCaustic);
    this->ui->plot->graph(1)->setData(this->y1Caustic, this->y2Caustic);

    this->ui->plot->addGraph();
    this->ui->plot->graph(2)->setLineStyle(QCPGraph::lsNone);
    this->ui->plot->graph(2)->setScatterStyle(scatterImages);
    this->ui->plot->graph(2)->setData(this->imagesX, this->imagesY);

    this->ui->plot->replot();
}

void SimulationDialog::critical(Model *model){
    /******** Me lo estoy sacando de la manga */
    double phi = model->getParameter("Phi")->getCurrentValue();
    double d0 = (M_PI * phi) / 180.0;

    double gamma = model->getParameter("Gamma")->getCurrentValue();
    double sigma = model->getParameter("Sigma")->getCurrentValue();
    model->setA1(1.0 - sigma - gamma * cos(2.0 * d0));
    model->setA2(1.0 - sigma + gamma * cos(2.0 * d0));
    model->setD(- gamma * sin(2.0 * d0));
    /*********************************/

    this->x1Caustic.clear();
    this->x2Caustic.clear();

    for(int x = - 4.00 / this->simulationParameters->getCausticDX(); x <=  4.00 / this->simulationParameters->getCausticDX(); ++x){
        for(int y = - 4.00 / this->simulationParameters->getCausticDX(); y <= 4.00 / this->simulationParameters->getCausticDX(); ++y){
            double xCritic = x * this->simulationParameters->getCausticDX();
            double yCritic = y * this->simulationParameters->getCausticDX();

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

    double phi = model->getParameter("Phi")->getCurrentValue();
    double d0 = (M_PI * phi) / 180.0;

    double gamma = model->getParameter("Gamma")->getCurrentValue();
    double sigma = model->getParameter("Sigma")->getCurrentValue();
    model->setA1(1.0 - sigma - gamma * cos(2.0 * d0));
    model->setA2(1.0 - sigma + gamma * cos(2.0 * d0));
    model->setD(- gamma * sin(2.0 * d0));

    double yeq1 = model->getA1() * x1 + model->getD() * x2 - alphaX;
    double yeq2 = model->getA2() * x2 + model->getD() * x1 - alphaY;

    model->setAlphas(x1, x2);

    *y1 = yeq1 - model->getAlpha1();
    *y2 = yeq2 - model->getAlpha2();
}
