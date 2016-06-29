//
//  NormalizedLayer.h
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/29/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#ifndef __NeuralNetwork__NormalizedLayer__
#define __NeuralNetwork__NormalizedLayer__

#include "BaseLayer.h"

/*

This is a child class to BaseLayer that normalized the output from the layer so that the outputs all add up to one. This is a slightly more general version of softmax (since here we're not committed to only using sigmoid functions. This introduces another subtlety in that we must ensure that the outputs don't already add up to zero since then they cannot be normalized. In order to avoid this issue, we normalize by the num of the magnitudes instead. In the case of softmax this makes no difference since then all ouputs are positive anyway.
*/

class NormalizedLayer: public BaseLayer{
public:
    NormalizedLayer(std::vector<Neuron*> neurons);
    std::vector<double> computeLayer();
    std::vector<double> computeLayer(std::vector<double> alternateInputs);
};

#endif /* defined(__NeuralNetwork__NormalizedLayer__) */
