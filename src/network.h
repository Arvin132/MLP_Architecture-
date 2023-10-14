#ifndef __MLP_NETWORK__
#define __MLP_NETWORK__
#include "perceptron.hpp"
#include "helper.h"
#include "limiter.h"
#include <vector>
#include <set>
#include <cstdarg>

using std::string;
using std::vector;
using std::tuple;
using std::set;

const set<string> layerTypeNameList {
    "Dense Layer",
    "Normalization Layer",
    "Flatten Layer"
};


struct Layer{
    // virtual string getTypeName() = 0;
    virtual void initLayer();
};


struct DenseLayer: public Layer { 
    
    vector<Perceptron> neurons;
    LimiterType limiterType = LimiterType::RELU;
    int neuronAmount;
    int pos;

    DenseLayer(int neuronAmount, LimiterType activationType = LimiterType::RELU): Layer{}, neurons(), limiterType(activationType) 
                                                                                  ,neuronAmount(neuronAmount){}
    
    // string getTypeName() override final;
};

typedef struct {
    Perceptron *from;
    Perceptron *to;
    double weight;
} Connection;


class Network {
    int numberOfLayers;
    vector<DenseLayer> layers;
    vector<Connection> layersConnections;
    InitMethod initMethod = InitMethod::UNIFORM;


    public:
        Network();
        ~Network();

        void SetTrainInput(vector<vector<double>> in, vector<vector<double>> labels);
        void CompileModel();
        void fitData(int epochs);
        void evaluateData();
        
        /* 
            used for precdicting a single instace
            returns a tuple holding:               ( loss_value, test_accuracy)

        */
        tuple<double, double> modelEvaluate(vector<double> test, double label);
        
        /* 
            used for precdicting a set of instaces
            returns a vector of tuples holding:   ( loss_value, test_accuracy)

        */
        vector<tuple<double, double>> modelEvaluate(vector<vector<double>> test, vector<double> label);

};

#endif