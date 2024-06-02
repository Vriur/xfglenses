#ifndef SIMULATIONPARAMETERS_H
#define SIMULATIONPARAMETERS_H

#include <map>
#include <string>
#include <QObject>

using std::map;
using std::pair;
using std::string;
using std::vector;

class SimulationParameters: public QObject
{
    Q_OBJECT

public:
    SimulationParameters();
    ~SimulationParameters();
    double getCausticDX();
    double getCausticTOL();
    void setSourceType(string sourceType);
    string getSourceType();
    void setImageFilePath(string imageFilePath);
    string getImageFilePath();
    void setSourcePositionX(double x);
    void setSourcePositionY(double y);
    pair<double, double> getSourcePosition(); 
    pair<double, double> getAnimationSourceInitialPosition();
    pair<double, double> getAnimationSourceFinalPosition();
    bool getShowInGraph(string key);
    pair<double, double>* getImage(int index);
    vector<pair<double, double>*> getImages();
    int getImagesLength();
    void createImage(double x = 0.0, double y = 0.0);
    void editImageX(double x, int index);
    void editImageY(double y, int index);
    void deleteImage(int index);
    void clearImages();

public slots:
    void setCausticDX(double causticDX);
    void setCausticTOL(double causticTol);
    void setAnimationSourceInitialPositionX(double x);
    void setAnimationSourceInitialPositionY(double y);
    void setAnimationSourceFinalPositionX(double x);
    void setAnimationSourceFinalPositionY(double y);
    void setShowInGraph(string key, bool value);

private:
    double causticDX;
    double causticTOL;
    string sourceType;
    string imageFilePath;
    pair<double, double> sourcePosition;
    pair<double, double> animationSourceInitialPosition;
    pair<double, double> animationSourceFinalPosition;
    map<string, bool> showInGraph;
    vector<pair<double, double> *> images;
};

#endif // SIMULATIONPARAMETERS_H
