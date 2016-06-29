//
//  NeuralNetwork.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/28/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(std::vector<int> neuronCounts, int numInputs, bool normalized){
    this->numInputs = numInputs;
    for(int i = 0; i < neuronCounts.size(); i++){
        std::vector<Neuron*> neurons;
        for(int j = 0; j < neuronCounts[i]; j++){
        
            Neuron* n;
            if(i == 0){
                n = new SigmoidUnit(numInputs); //input layer
            } else if (i < neuronCounts.size() - 1 || !normalized){
                n = new SigmoidUnit(neuronCounts[i-1]); //connect to previous layer
            } else{ //gets executed on last layer if and only if normalized has been set to true (i.e. we want a normalized/softmax final layer)
                n = new ExponentialNeuron(neuronCounts[i-1]); //connect to previous layer
            }
            neurons.push_back(n);
        }
        
        BaseLayer* layer;
        if(!normalized || i < neuronCounts.size() - 1){
            layer = new Layer(neurons);
        } else{ //last layer is a normalized layer iff normalized is set to true
            layer = new NormalizedLayer(neurons);
        }
        
        if(i>0){
            layer->setPrevLayer(layers[i-1]); //link up with previous layer if it's not the input layer
        }
        layers.push_back(layer);
    }
}
std::vector<double> NeuralNetwork::forwardPropagate(std::vector<double> inputs){

    layers[0]->computeLayer(inputs); //input layer
    for(int i = 1; i < layers.size() - 1; i++){
        layers[i]->computeLayer();
    }
    output = layers[layers.size()-1]->computeLayer(); //output layer
    return output;
}

void NeuralNetwork::printWeightsByLayer(){
    for(int i = 0; i < layers.size(); i++){
        std::cout << "*** Layer " << i << " ***" << std::endl;
        layers[i]->printWeightMatrix();
    }
}

void NeuralNetwork::printOutputs(){
    std::cout << "Output by Neural Network: ";
    for(int i = 0; i < output.size(); i++){
        std::cout << output[i] << " ";
    }
    std::cout << std::endl;
}