//
//  NormalizedLayer.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/29/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include "NormalizedLayer.h"

NormalizedLayer::NormalizedLayer(std::vector<Neuron*> neurons): BaseLayer(neurons){}
std::vector<double> NormalizedLayer::computeLayer(){
    double normalization = 0.0;
    for(int i = 0; i < numUnits; i++){
        outputs[i] = neurons[i]->compute(this->prevLayer->outputs);
        normalization += fabs(outputs[i]);
    }
    if(normalization == 0.0){ //all outputs were zero for some reason, so we can't normalize them and therefore just keep them the way they are
        return outputs;
    }
    for(int i = 0; i < numUnits; i++){
        outputs[i] /= normalization;
    }
    return outputs;
}
std::vector<double> NormalizedLayer::computeLayer(std::vector<double> alternateInputs){
    double normalization = 0.0;
    for(int i = 0; i < numUnits; i++){
        outputs[i] = neurons[i]->compute(alternateInputs);
        normalization += outputs[i];
    }
    if(normalization == 0.0){ //all outputs were zero for some reason, so we can't normalize them and therefore just keep them the way they are
        return outputs;
    }
    for(int i = 0; i < numUnits; i++){
        outputs[i] /= normalization;
    }
    return outputs;

}