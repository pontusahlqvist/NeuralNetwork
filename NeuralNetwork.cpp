//
//  NeuralNetwork.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/28/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(std::vector<std::string> neuronTypes, int numInputs, bool normalized){
    this->numInputs = numInputs;
    for(int i = 0; i < neuronTypes.size(); i++){
        std::vector<Neuron*> neurons;
        for(int j = 0; j < neuronTypes[i].length(); j++){
        
            Neuron* n;
            if(i == 0){
                n = generateNeuron(neuronTypes[i][j], numInputs);
            } else if (i < neuronTypes.size() || !normalized){
                n = generateNeuron(neuronTypes[i][j], (int)neuronTypes[i-1].length()); //connect to previous layer
            }
            neurons.push_back(n);
        }
        
        BaseLayer* layer;
        if(!normalized || i < neuronTypes.size() - 1){
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

Neuron* NeuralNetwork::generateNeuron(char type, int numInputs){
    Neuron* n;
    if(type == 'e'){
        n = new ExponentialNeuron(numInputs);
    } else if(type == 's'){
        n = new SigmoidNeuron(numInputs);
    } else if(type == 'l'){
        n = new LinearNeuron(numInputs);
    } else if(type == 't'){
        n = new TanhNeuron(numInputs);
    } else{ //must have a default. Choose to be sigmoid
        n = new SigmoidNeuron(numInputs); //input layer
    }
    return n;
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