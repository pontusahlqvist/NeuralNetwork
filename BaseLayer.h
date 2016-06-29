//
//  BaseLayer.h
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/27/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#ifndef __NeuralNetwork__BaseLayer__
#define __NeuralNetwork__BaseLayer__

#include <vector>
#include <iostream>
#include "Neuron.h"

/*

Each Layer contains a std::vector<Neuron*> which represents the neurons in the layer. Each layer has a previous layer and next layer (except first and last one). There are two types of compute methods depending on if it's an input layer (in which case the alternateInputs overloading is used) or a regular hidden/output layer (in which case the standard computeLayer() method is called without arguments).
*/

class BaseLayer{
protected:
    BaseLayer* prevLayer;
    BaseLayer* nextLayer;

    int numUnits;

    std::vector<Neuron*> neurons;
public:
    std::vector<double> outputs;
    BaseLayer(std::vector<Neuron*> neurons);
    void setPrevLayer(BaseLayer* newPrevLayer);
    void setNextLayer(BaseLayer* newNextLayer);
    virtual std::vector<double> computeLayer() = 0;
    virtual std::vector<double> computeLayer(std::vector<double> alternateInputs) = 0; //this allows the layer to also be used as an input layer.
    void printWeightMatrix();

};

#endif /* defined(__NeuralNetwork__BaseLayer__) */
