#ifndef CAUSTICDIALOG_H
#define CAUSTICDIALOG_H

#include "../../logic/headers/simulationparameters.h"

#include <string>
#include <QDialog>

using std::string;

namespace Ui {
class CausticDialog;
}

class CausticDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CausticDialog(QWidget *parent, SimulationParameters &simulationParameters);
    ~CausticDialog();

signals:
    void updateDXValue(double value);
    void updateTOLValue(double value);
    void updateBoolValue(string key, bool value);

private slots:
    void on_DoneBtn_clicked();

    void on_DXSpnBox_valueChanged(double arg1);

    void on_TOLSpnBox_valueChanged(double arg1);

    void on_CriticalCurvesChkBox_stateChanged(int arg1);

    void on_CausticsChkBox_stateChanged(int arg1);

private:
    Ui::CausticDialog *ui;
};

#endif // CAUSTICDIALOG_H
