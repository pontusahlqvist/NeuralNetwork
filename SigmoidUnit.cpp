//
//  SigmoidUnit.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/26/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include "SigmoidUnit.h"

SigmoidUnit::SigmoidUnit(int numInputs):Neuron(numInputs){}

double SigmoidUnit::compute(std::vector<double> inputs){
    double activation = this->activation(inputs);
    return 1.0/(1.0 + exp(-activation));
}
