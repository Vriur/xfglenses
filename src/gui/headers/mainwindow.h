#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "src/models/headers/model.h"
#include "src/gui/headers/causticdialog.h"
#include "src/gui/headers/fittingdialog.h"
#include "src/gui/headers/helpdialog.h"
#include "src/gui/headers/lightcurvedialog.h"
#include "src/gui/headers/modelsdialog.h"
#include "src/gui/headers/obipdialog.h"
#include "src/gui/headers/trackdialog.h"

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
