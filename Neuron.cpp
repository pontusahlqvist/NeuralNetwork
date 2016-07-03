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
    error = 0.0;
    
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

double Neuron::computeActivation(std::vector<double> inputs){
    activation = 0.0;
    for(int i = 0; i < numInputs; i++){
        activation += weights[i+1]*inputs[i];
    }
    activation += weights[0]; //bias input
    return activation;
}

void Neuron::incrementWeights(std::vector<double> inputs, double learningRate){
    for(int i = 0; i <= numInputs; i++){ //note that bias is also among weights
        weights[i] += -learningRate*inputs[i]*error;
    } 
}

void Neuron::printWeights(){
    std::cout << "(";
    for(int i = 0; i < numInputs; i++){
        std::cout << weights[i] << ",";
    }
    std::cout << weights[numInputs] << ")" << std::endl;
}

double Neuron::computeErrorContribution(int inputIndex){
    return weights[inputIndex+1]*error;
}

double Neuron::computeError(std::vector<double> errorContributions){
    error = 0.0;
    for(int i = 0; i < errorContributions.size(); i++){
        error += errorContributions[i];
    }
    error *= computeDerivative();
    return error;
}

double Neuron::computeError(double correctOutput){
    error = output-correctOutput;
    return error; //should only be used for output layers
}



