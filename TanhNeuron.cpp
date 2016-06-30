//
//  TanhNeuron.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/29/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include "TanhNeuron.h"
TanhNeuron::TanhNeuron(int numInputs):Neuron(numInputs){}
double TanhNeuron::compute(std::vector<double> inputs){
    double activation = this->activation(inputs);
    return tanh(activation);
}