//
//  main.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/26/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include <iostream>
#include "SigmoidUnit.h"
#include "Layer.h"
#include "NeuralNetwork.h"

int main(int argc, const char * argv[]) {

    //create the std::vector that will hold all the Neuron counts. This setup creates a network with 5 units in the first layer, 2 in the second, and 1 in the output layer. There are also 10 input features (as specified by numInputs) that are fed into the first (5 neuron) layer.
    std::vector<int> neuronCounts;
    neuronCounts.push_back(5);
    neuronCounts.push_back(2);
    neuronCounts.push_back(1);
    int numInputs = 10;
    NeuralNetwork ANN(neuronCounts, numInputs);
    
    //inputs into Neural Network (in this example, all input features are present)
    std::vector<double> alternateInputs;
    for(int i = 0; i < numInputs; i++){
        alternateInputs.push_back(1.0);
    }
    
    //This is where we actually create the neural network and propagate the features above through it once.
    std::vector<double> outputs = ANN.forwardPropagate(alternateInputs);
    ANN.printWeightsByLayer();
    ANN.printOutputs();

    return 0;
}
