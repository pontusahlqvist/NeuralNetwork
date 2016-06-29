//
//  Layer.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/27/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include "BaseLayer.h"

BaseLayer::BaseLayer(std::vector<Neuron*> neurons){
    this->neurons = neurons; //TODO: make this more efficient. Perhaps pass by reference or by pointer
    numUnits = (int)neurons.size();
    this->outputs.resize(neurons.size());
    prevLayer = 0;
    nextLayer = 0;
}

void BaseLayer::setPrevLayer(BaseLayer *newPrevLayer){
    this->prevLayer = newPrevLayer;
    newPrevLayer->nextLayer = this;
}

void BaseLayer::setNextLayer(BaseLayer *newNextLayer){
    this->nextLayer = newNextLayer;
    newNextLayer->prevLayer = this;
}

void BaseLayer::printWeightMatrix(){
    for(int i = 0; i < numUnits; i++){
        neurons[i]->printWeights();
    }
}

