#ifndef SIMULATIONDIALOG_H
#define SIMULATIONDIALOG_H

#define _USE_MATH_DEFINES
#define CONVERTIONFACTOR 0.01
#define LIMIT 400

#include "src/models/headers/model.h"
#include "src/logic/headers/simulationparameters.h"
#include "../../libraries/qcustomplot.h"

#include <math.h>
#include <QDialog>

namespace Ui {
class SimulationDialog;
}

class SimulationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SimulationDialog(QWidget *parent, vector<Model*> &simulationModels, SimulationParameters &simulationParameters);
    ~SimulationDialog();
    void images(Model *model);
    void caustic(Model *model);
    void critical(Model *model);
    void lensEquation(Model *model, double x1, double x2, double *y1, double *y2);

private:
    Ui::SimulationDialog *ui;
    SimulationParameters *simulationParameters;
    vector<Model*> *simulationModels;
    bool blackHole;
    QVector<double> imagesX;
    QVector<double> imagesY;
    QVector<double> x1Caustic;
    QVector<double> x2Caustic;
    QVector<double> y1Caustic;
    QVector<double> y2Caustic;
};

#endif // SIMULATIONDIALOG_H
