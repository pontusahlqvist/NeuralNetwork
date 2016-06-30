//
//  NeuralNetwork.h
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/28/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#ifndef __NeuralNetwork__NeuralNetwork__
#define __NeuralNetwork__NeuralNetwork__

#include <vector>
#include <string>
#include "Layer.h"
#include "SigmoidNeuron.h"
#include "ExponentialNeuron.h"
#include "LinearNeuron.h"
#include "TanhNeuron.h"
#include "NormalizedLayer.h"

/*

The user determines both the number of layers and the number of units in each layer by passing a std::vector<int> to the constructor. Additionally the user passes the number of inputs to the constructor. The method forwardPropagate() sequentially calls the computeLayer() methods from the layers, making sure that the first layer is called with the inputs to the neural network.

*/

class NeuralNetwork{
protected:
    std::vector<BaseLayer*> layers;
    std::vector<double> output;
    int numInputs;
    Neuron* generateNeuron(char type, int numInputs);
public:
    NeuralNetwork(std::vector<std::string> neuronTypes, int numInputs, bool normalized = false);
    std::vector<double> forwardPropagate(std::vector<double> inputs);
    void printWeightsByLayer();
    void printOutputs();
};

#endif /* defined(__NeuralNetwork__NeuralNetwork__) */
