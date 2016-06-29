//
//  SigmoidUnit.h
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/26/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#ifndef __NeuralNetwork__SigmoidUnit__
#define __NeuralNetwork__SigmoidUnit__

#include <vector>
#include <iostream>
#include "Neuron.h"
#include "math.h"

/*

This is a child class to the parent class Neuron. Here we implement the sigmoidal computation unit.

*/

class SigmoidUnit: public Neuron{
public:
    SigmoidUnit(int numInputs);
    double compute(std::vector<double> inputs);
};

#endif /* defined(__NeuralNetwork__SigmoidUnit__) */
