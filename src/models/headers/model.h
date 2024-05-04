#ifndef MODEL_H
#define MODEL_H

#include "modelparameter.h"

#include <QDebug>

using std::string;
using std::vector;

class Model
{
public:
    void setName(string name){
        this->name = name;
    }

    string getName(){
        return this->name;
    }

    void setParameter(int &index, double &newValue){
        parameters[index]->setCurrentValue(newValue);
    }

    ModelParameter* getParameter(int &index){
        return parameters[index];
    }

    void setParameters(vector<ModelParameter*> &newParameters){
        parameters.clear();
        parameters = newParameters;
    }

    vector<ModelParameter *> getParameters(){
        return parameters;
    }

    void printParameters(){
        for(auto &parameter : parameters){
            qDebug() << parameter->getName();
        }
    }

protected:
    string name = "";
    vector<ModelParameter *> parameters;
};

#endif // MODEL_H
