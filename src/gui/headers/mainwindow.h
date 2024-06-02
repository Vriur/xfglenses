#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimeLine>

#include "src/models/headers/model.h"
#include "src/gui/headers/causticdialog.h"
#include "src/gui/headers/fittingdialog.h"
#include "src/gui/headers/helpdialog.h"
#include "src/gui/headers/lightcurvedialog.h"
#include "src/gui/headers/modelsdialog.h"
#include "src/gui/headers/obipdialog.h"
#include "src/gui/headers/trackdialog.h"

#include "src/logic/headers/simulationparameters.h"

using std::vector;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    SimulationParameters simulationParameters;
    vector<Model*> simulationModels;

private slots:
    void on_CausticBtn_clicked();

    void on_FittingBtn_clicked();

    void on_HelpBtn_clicked();

    void on_ImageFileBtn_clicked();

    void on_LightCurveBtn_clicked();

    void on_ModelsBtn_clicked();

    void on_OBIPBtn_clicked();

    void on_TrackBtn_clicked();

    void on_PrintBtn_clicked();

    void on_SourceChkBtn_stateChanged(int arg1);

    void on_ImagesChkBtn_stateChanged(int arg1);

    void on_GridChkBtn_stateChanged(int arg1);

    void on_RayPlotChkBtn_stateChanged(int arg1);

    void on_RootsChkBtn_stateChanged(int arg1);

    void on_R_EChkBtn_stateChanged(int arg1);

    void on_ContourChkBtn_stateChanged(int arg1);

    void on_InversionChkBtn_stateChanged(int arg1);

    void on_TimeDelayChkBtn_stateChanged(int arg1);

    void on_XSpBox_valueChanged(double arg1);

    void on_YSpBox_valueChanged(double arg1);

    void on_SourceMenuCmBox_currentTextChanged(const QString &arg1);

    void updateSourceCoordinates(double x, double y);

    void startAnimation(QTimeLine *timer, double initialX, double initialY, double finalX, double finalY);

private:
    Ui::MainWindow *ui;
    CausticDialog *causticDialog;
    FittingDialog *fittingDialog;
    HelpDialog *helpDialog;
    LightCurveDialog *lightCurveDialog;
    ModelsDialog *modelsDialog;
    OBIPDialog *obipDialog;
    TrackDialog *trackDialog;
};
#endif // MAINWINDOW_H
