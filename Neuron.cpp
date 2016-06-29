//
//  Neuron.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/26/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include "Neuron.h"


Neuron::Neuron(int numInputs){
    this->numInputs = numInputs;
    
    //Randomly initialize the weights from a normal distribution with standard deviation sigma and mean zero
    double sigma = 0.1;
    unsigned int seed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> distribution(0.0,sigma);
    
    for(int i = 0; i <= numInputs; i++){ //initialize the weights
        weights.push_back(distribution(generator));
    }
}

Neuron::~Neuron(){}

double Neuron::activation(std::vector<double> inputs){
    double innerProduct = 0.0;
    for(int i = 0; i < numInputs; i++){
        innerProduct += weights[i+1]*inputs[i];
    }
    innerProduct += weights[0]; //bias input
    return innerProduct;
}

void Neuron::incrementWeights(std::vector<double> deltas){
    for(int i = 0; i <= numInputs; i++){ //note that bias is also among weights
        weights[i] += deltas[i];
    } 
}

void Neuron::printWeights(){
    std::cout << "(";
    for(int i = 0; i < numInputs; i++){
        std::cout << weights[i] << ",";
    }
    std::cout << weights[numInputs] << ")" << std::endl;
}