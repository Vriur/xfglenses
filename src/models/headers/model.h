#ifndef MODEL_H
#define MODEL_H

#include "modelparameter.h"

#include <math.h>

using std::string;
using std::vector;

class Model
{
public:
    virtual double jacobian(double x, double y) = 0;
    virtual void setAlphas(double x1, double x2) = 0;

    double getAlpha1(){
        return this->alpha1;
    }

    double getAlpha2(){
        return this->alpha2;
    }

    void setA1(double A1){
        this->A1 = A1;
    }

    double getA1(){
        return this->A1;
    }

    void setA2(double A2){
        this->A2 = A2;
    }

    double getA2(){
        return this->A2;
    }

    void setD(double D){
        this->D = D;
    }

    double getD(){
        return this->D;
    }

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

    ModelParameter* getParameter(string name){
        ModelParameter* parameter = nullptr;
        bool findParameter = false;
        int iterator = 0;

        while(iterator < (int) this->parameters.size() && !findParameter){
            if(name.compare(this->parameters.at(iterator)->getName()) == 0){
                parameter = this->parameters.at(iterator);
                findParameter = true;
            }
            ++iterator;
        }

        return parameter;
    }

    void setParameters(vector<ModelParameter*> newParameters){
        parameters.clear();
        parameters = newParameters;
    }

    vector<ModelParameter *> getParameters(){
        return parameters;
    }

protected:
    double alpha1 = 0.00;
    double alpha2 = 0.00;
    double A1 = 0.00;
    double A2 = 0.00;
    double D = 0.00;
    string name = "";
    vector<ModelParameter *> parameters;
};

#endif // MODEL_H
