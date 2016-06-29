//
//  Layer.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/28/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include "Layer.h"


Layer::Layer(std::vector<Neuron*> neurons): BaseLayer(neurons){}

std::vector<double> Layer::computeLayer(){
    for(int i = 0; i < numUnits; i++){
        outputs[i] = neurons[i]->compute(this->prevLayer->outputs);
    }
    return outputs;
}

std::vector<double> Layer::computeLayer(std::vector<double> alternateInputs){
    for(int i = 0; i < numUnits; i++){
        outputs[i] = neurons[i]->compute(alternateInputs);
    }
    return outputs;
}