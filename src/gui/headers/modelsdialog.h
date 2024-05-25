#ifndef MODELSDIALOG_H
#define MODELSDIALOG_H

#include "src/gui/headers/modelscell.h"
#include "src/models/headers/model.h"
#include "src/models/headers/modelparameter.h"

#include <QDialog>
#include <QVBoxLayout>

using std::vector;

namespace Ui {
class ModelsDialog;
}

class ModelsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModelsDialog(QWidget *parent, vector<Model*> &simulationModels);
    ~ModelsDialog();
    void createCell(Model *model = nullptr);

    vector<Model*> *simulationModels;

public slots:
    void deleteCell(int index);
    void changeSimulationModel(string modelName, int index);

signals:
    void loadParameters(vector<ModelParameter*> parameters, int index);

private slots:
    void on_AddBtn_clicked();

    void on_DoneBtn_clicked();

private:
    Ui::ModelsDialog *ui;
    vector<ModelsCell*> selectedModels;
    int modelsNum;
};

#endif // MODELSDIALOG_H
