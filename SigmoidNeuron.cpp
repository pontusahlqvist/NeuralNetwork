//
//  SigmoidNeuron.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/26/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include "SigmoidNeuron.h"

SigmoidNeuron::SigmoidNeuron(int numInputs):Neuron(numInputs){}

double SigmoidNeuron::compute(std::vector<double> inputs){
    double activation = this->activation(inputs);
    return 1.0/(1.0 + exp(-activation));
}
