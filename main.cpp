//
//  main.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/26/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include <iostream>
#include <string>
#include "NeuralNetwork.h"

int main(int argc, const char * argv[]) {

    //create the std::vector that will hold all the Neuron types. Each element of this list contains a string of character each of which identifies a type of neuron. For example, s = sigmoidal, e = exponential, l = linear, t = tanh.
    std::vector<std::string> neuronTypes;
    neuronTypes.push_back("sssss");
    neuronTypes.push_back("tlse");
    neuronTypes.push_back("lel");
    int numInputs = 10;
    NeuralNetwork ANN(neuronTypes, numInputs, true);
    
    //inputs into Neural Network (in this example, all input features are present)
    std::vector<double> inputs;
    for(int i = 0; i < numInputs; i++){
        inputs.push_back(1.0);
    }
    
    //This is where we actually create the neural network and propagate the features above through it once.
    std::vector<double> outputs = ANN.forwardPropagate(inputs);
    ANN.printWeightsByLayer();
    ANN.printOutputs();

    return 0;
}
