#ifndef OBIPDIALOG_H
#define OBIPDIALOG_H

#include "src/gui/headers/obipcell.h"
#include "src/logic/headers/simulationparameters.h"

#include <QDialog>
#include <vector>

using std::pair;
using std::vector;

namespace Ui {
class OBIPDialog;
}

class OBIPDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OBIPDialog(QWidget *parent, SimulationParameters &simulationParameters);
    ~OBIPDialog();
    void createCell(pair<double, double>* image = new pair(0.0, 0.0));

    SimulationParameters *simulationParameters;
    
public slots:
    void updateX(double x, int index);
    void updateY(double y, int index);
    void deleteCell(int index);

private slots:
    void on_DoneBtn_clicked();

    void on_AddBtn_clicked();

    void on_ClearBtn_clicked();

private:
    Ui::OBIPDialog *ui;
    vector<OBIPCell*> imagesWidgets;
    int imagesNum;
};

#endif // OBIPDIALOG_H
