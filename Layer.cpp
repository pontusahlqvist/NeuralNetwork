//
//  Layer.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/27/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include "Layer.h"

Layer::Layer(std::vector<Neuron*> neurons, bool normalized){
    this->neurons = neurons; //TODO: make this more efficient. Perhaps pass by reference or by pointer
    numUnits = (int)neurons.size();
    this->outputs.resize(neurons.size());
    prevLayer = 0;
    nextLayer = 0;
    this->normalized = normalized;
}

void Layer::setPrevLayer(Layer *newPrevLayer){
    this->prevLayer = newPrevLayer;
    newPrevLayer->nextLayer = this;
}

void Layer::setNextLayer(Layer *newNextLayer){
    this->nextLayer = newNextLayer;
    newNextLayer->prevLayer = this;
}

void Layer::printWeightMatrix(){
    for(int i = 0; i < numUnits; i++){
        neurons[i]->printWeights();
    }
}

std::vector<double> Layer::computeLayer(){
    return computeLayer(this->prevLayer->outputs);
}

std::vector<double> Layer::computeLayer(std::vector<double> alternateInputs){
    double normalization = 0.0;
    for(int i = 0; i < numUnits; i++){
        outputs[i] = neurons[i]->compute(alternateInputs);
        normalization += fabs(outputs[i]);
    }
    if(!normalized || normalization == 0.0){
        return outputs;
    }
    for(int i = 0; i < numUnits; i++){
        outputs[i] /= normalization;
    }
    return outputs;
}