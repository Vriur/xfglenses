#include "src/gui/headers/modelsdialog.h"
#include "ui_modelsdialog.h"

#include "src/gui/headers/modelscell.h"
#include "src/models/headers/barkanamodel.h"
#include "src/models/headers/changrefsdalmodel.h"
#include "src/models/headers/devancoulermodel.h"
#include "src/models/headers/elliptichubblemodel.h"
#include "src/models/headers/elliptickingmodel.h"
#include "src/models/headers/ellipticmodel.h"
#include "src/models/headers/ellipticnismodel.h"
#include "src/models/headers/ellipticplummermodel.h"
#include "src/models/headers/ellipticsismodel.h"
#include "src/models/headers/hubblemodel.h"
#include "src/models/headers/kassiolakovnermodel.h"
#include "src/models/headers/kingmodel.h"
#include "src/models/headers/multipolemodel.h"
#include "src/models/headers/nfwmodel.h"
#include "src/models/headers/nismodel.h"
#include "src/models/headers/rotationlensmodel.h"
#include "src/models/headers/secondordermodel.h"
#include "src/models/headers/sismodel.h"
#include "src/models/headers/spiralmodel.h"
#include "src/models/headers/transparentspheremodel.h"
#include "src/models/headers/truncatedkingmodel.h"
#include "src/models/headers/uniformringmodel.h"

using std::map;

ModelsDialog::ModelsDialog(QWidget *parent, vector<Model*> &simulationModels)
    : QDialog(parent)
    , ui(new Ui::ModelsDialog)
{
    ui->setupUi(this);
    this->showMaximized();
    this->simulationModels = &simulationModels;
    this->modelsNum = 0;

    for(auto model : simulationModels){
        this->createCell(model);
    }
}

ModelsDialog::~ModelsDialog()
{
    delete ui;
}

void ModelsDialog::on_AddBtn_clicked()
{
    Model *newModel = nullptr;

    this->createCell();
    this->simulationModels->push_back(newModel);
}

void ModelsDialog::on_DoneBtn_clicked()
{
    this->close();
}

void ModelsDialog::createCell(Model *model){
    ModelsCell *newCell = new ModelsCell(this, model, modelsNum);
    newCell->setAttribute(Qt::WA_DeleteOnClose);

    this->ui->ScrollLayout->addWidget(newCell);
    this->selectedModels.push_back(newCell);
    this->modelsNum++;

    connect(newCell, SIGNAL(deleteThisCell(int)), this, SLOT(deleteCell(int)));
    connect(newCell, SIGNAL(changeSimulationModel(string, int)), this, SLOT(changeSimulationModel(string, int)));
    connect(this, SIGNAL(loadParameters(vector<ModelParameter*>, int)), newCell, SLOT(loadParameters(vector<ModelParameter*>, int)));
}

void ModelsDialog::deleteCell(int index){
    for(int i = index + 1; i < (int) selectedModels.size(); i++){
        selectedModels[i]->setIndex(selectedModels[i]->getIndex() - 1);
    }

    this->selectedModels[index]->close();
    this->selectedModels.erase(std::next(selectedModels.begin(), index));
    this->simulationModels->erase(std::next(simulationModels->begin(), index));
    this->modelsNum--;
}

void ModelsDialog::changeSimulationModel(string modelName, int index){
    map<string, int> models = {
        {"Model Menu", -1},
        {"Chang-Refsdal", 1},
        {"SIS", 2},
        {"NIS", 3},
        {"Transparent Sphere", 4},
        {"Elliptic Model", 5},
        {"King Model", 6},
        {"Truncated King", 7},
        {"Hubble Model", 8},
        {"De Vancouleur", 9},
        {"Spiral Model", 10},
        {"Multipole Model", 11},
        {"Rotation Lens", 12},
        {"Uniform Ring", 13},
        {"Second Order", 14},
        {"Elliptic SIS", 15},
        {"Elliptic King", 16},
        {"Elliptic Hubble", 17},
        {"Elliptic NIS", 18},
        {"Elliptic Plummer", 19},
        {"Kassiola-Kovner", 20},
        {"NFW", 21},
        {"Barkana", 22},
    };

    if(simulationModels->at(index) != nullptr){
        delete simulationModels->at(index);
    }

    switch(models.at(modelName)){
        case 1:
            simulationModels->at(index) = new ChangRefsdalModel();
            break;

        case 2:
            simulationModels->at(index) = new SISModel();
            break;

        case 3:
            simulationModels->at(index) = new NISModel();
            break;

        case 4:
            simulationModels->at(index) = new TransparentSphereModel();
            break;

        case 5:
            simulationModels->at(index) = new EllipticModel();
            break;

        case 6:
            simulationModels->at(index) = new KingModel();
            break;

        case 7:
            simulationModels->at(index) = new TruncatedKingModel;
            break;

        case 8:
            simulationModels->at(index) = new HubbleModel();
            break;

        case 9:
            simulationModels->at(index) = new DeVancoulerModel();
            break;

        case 10:
            simulationModels->at(index) = new SpiralModel();
            break;

        case 11:
            simulationModels->at(index) = new MultipoleModel();
            break;

        case 12:
            simulationModels->at(index) = new RotationLensModel();
            break;

        case 13:
            simulationModels->at(index) = new UniformRingModel();
            break;

        case 14:
            simulationModels->at(index) = new SecondOrderModel();
            break;

        case 15:
            simulationModels->at(index) = new EllipticSISModel();
            break;

        case 16:
            simulationModels->at(index) = new EllipticKingModel();
            break;

        case 17:
            simulationModels->at(index) = new EllipticHubbleModel();
            break;

        case 18:
            simulationModels->at(index) = new EllipticNISModel();
            break;

        case 19:
            simulationModels->at(index) = new EllipticPlummerModel();
            break;

        case 20:
            simulationModels->at(index) = new KassiolaKovnerModel();
            break;

        case 21:
            simulationModels->at(index) = new NFWModel();
            break;

        case 22:
            simulationModels->at(index) = new BarkanaModel();
            break;

        default:
            simulationModels->at(index) = nullptr;
    }

    if(simulationModels->at(index) != nullptr){
        emit this->loadParameters(simulationModels->at(index)->getParameters(), index);
    }
}
