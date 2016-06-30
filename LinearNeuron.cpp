//
//  LinearNeuron.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/29/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include "LinearNeuron.h"

LinearNeuron::LinearNeuron(int numInputs):Neuron(numInputs){}
double LinearNeuron::compute(std::vector<double> inputs){
    double activation = this->activation(inputs);
    return activation;
}