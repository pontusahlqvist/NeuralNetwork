//
//  Layer.h
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/28/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#ifndef __NeuralNetwork__Layer__
#define __NeuralNetwork__Layer__

#include "BaseLayer.h"


class Layer: public BaseLayer{
public:
    Layer(std::vector<Neuron*> neurons);
    std::vector<double> computeLayer();
    std::vector<double> computeLayer(std::vector<double> alternateInputs); //this allows the layer to also be used as an input layer.
};

#endif /* defined(__NeuralNetwork__Layer__) */
