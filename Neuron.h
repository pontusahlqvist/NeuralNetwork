//
//  Neuron.h
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/26/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#ifndef __NeuralNetwork__Neuron__
#define __NeuralNetwork__Neuron__

#include <vector>
#include <chrono>
#include <random>
#include <iostream>
#include "math.h"

/*

This is an abstract base class that represents a computing unit (neuron). Child classes can implement various types of compute functions (tanh, sigmoid, linear, perceptron, ...). Since each layer stores a vector of Neuron*, we can use Polymorphism to put all the different types of units into a single unified layer simplifying the handling of more complex networks down the line.
*/

class Neuron{
protected:
    std::vector<double> weights; //will contain the weights for this neuron (note that bias is among these)
    int numInputs; //does not include bias
    double activation(std::vector<double> inputs);

public:
    Neuron(int numInputs);
    ~Neuron();
    virtual double compute(std::vector<double> inputs) = 0;
    void incrementWeights(std::vector<double> deltas);
    void printWeights();
};

#endif /* defined(__NeuralNetwork__Neuron__) */
