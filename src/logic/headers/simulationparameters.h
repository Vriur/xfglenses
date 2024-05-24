#ifndef SIMULATIONPARAMETERS_H
#define SIMULATIONPARAMETERS_H

#include <map>
#include <string>
#include <QObject>

using std::map;
using std::pair;
using std::string;

class SimulationParameters: public QObject
{
    Q_OBJECT

public:
    SimulationParameters();
    ~SimulationParameters();
    double getCausticDX();
    double getCausticTOL();
    void setSourceN(int sourceN);
    int getSourceN();
    void setSourceType(string sourceType);
    string getSourceType();
    void setImageFilePath(string imageFilePath);
    string getImageFilePath();
    void setSourcePositionX(double valueX);
    void setSourcePositionY(double valueY);
    pair<double, double> getSourcePosition(); 
    pair<double, double> getAnimationSourceInitialPosition();
    pair<double, double> getAnimationSourceFinalPosition();
    bool getShowInGraph(string key);

public slots:
    void setCausticDX(double causticDX);
    void setCausticTOL(double causticTol);
    void setAnimationSourceInitialPositionX(double valueX);
    void setAnimationSourceInitialPositionY(double valueY);
    void setAnimationSourceFinalPositionX(double valueX);
    void setAnimationSourceFinalPositionY(double valueY);
    void setShowInGraph(string key, bool value);

private:
    double causticDX;
    double causticTOL;
    int sourceN;
    string sourceType;
    string imageFilePath;
    pair<double, double> sourcePosition;
    pair<double, double> animationSourceInitialPosition;
    pair<double, double> animationSourceFinalPosition;
    map<string, bool> showInGraph;
};

#endif // SIMULATIONPARAMETERS_H
