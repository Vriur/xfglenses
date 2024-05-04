#ifndef MODELSCELL_H
#define MODELSCELL_H

#include "src/gui/headers/customslider.h"
#include "src/models/headers/model.h"
#include "src/models/headers/modelparameter.h"

#include <QDialog>
#include <QHBoxLayout>

using std::vector;

namespace Ui {
class ModelsCell;
}

class ModelsCell : public QDialog
{
    Q_OBJECT

public:
    explicit ModelsCell(QWidget *parent = nullptr, Model *model = nullptr, int index = -1);
    ~ModelsCell();
    void cleanScrollArea();
    void loadModel(Model *model);
    void setIndex(int index);
    int getIndex();

signals:
    void deleteThisCell(int index);
    void changeSimulationModel(string modelName, int index);

private slots:
    void on_ModelMenuCmBox_currentTextChanged(const QString &name);

    void on_DeleteBtn_clicked();

    void loadParameters(vector<ModelParameter*> parameters);

private:
    Ui::ModelsCell *ui;
    vector<CustomSlider*> parametersSliders;
    int index;
};

#endif // MODELSCELL_H
