//
//  main.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/26/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include <iostream>
#include <string>
#include "NeuralNetwork.h"

//This function takes the input string denoting the layer architecture and splits it on ',' and returns a vector of strings to be used by the ANN.
std::vector<std::string> splitIntoLayers(const char* input){
    std::vector<std::string> layerStrings;
    std::string tempString = "";
    for(const char* c = input; *c != '\0'; c++){
        if(*c == ','){
            layerStrings.push_back(tempString);
            tempString = "";
        } else{
            tempString += *c;
        }
    }
    if(tempString != ""){ //just in case someone terminated the list of layers with a comma: "ss,s,sss,"
        layerStrings.push_back(tempString);
    }
    return layerStrings;
}

int main(int argc, const char * argv[]) {

    //create the std::vector that will hold all the Neuron types. Each element of this list contains a string of character each of which identifies a type of neuron. For example, s = sigmoidal, e = exponential, l = linear, t = tanh.
    std::vector<std::string> neuronTypes;
    std::string neuronsInLayer = "";
    if(argc == 1){ //use default network if one isn't specified using the command line
        neuronTypes.push_back("ss");
        neuronTypes.push_back("s");
    } else{
        neuronTypes = splitIntoLayers(argv[1]);
    }

    //XOR example
    int numInputs = 2;
    NeuralNetwork ANN(neuronTypes, numInputs, false);

    std::vector<double> input1, input2, input3, input4;
    std::vector<double> correctOutput1, correctOutput2, correctOutput3, correctOutput4;
    input1.push_back(0.0);
    input1.push_back(0.0);
    correctOutput1.push_back(1.0);
    
    input2.push_back(0.0);
    input2.push_back(1.0);
    correctOutput2.push_back(0.0);
    
    input3.push_back(1.0);
    input3.push_back(0.0);
    correctOutput3.push_back(0.0);

    input4.push_back(1.0);
    input4.push_back(1.0);
    correctOutput4.push_back(1.0);
    
    std::cout << "*********  Pre-training Prediction **********" << std::endl;
    ANN.printWeightsByLayer();
    ANN.forwardPropagate(input1);
    ANN.printOutputs();
    ANN.forwardPropagate(input2);
    ANN.printOutputs();
    ANN.forwardPropagate(input3);
    ANN.printOutputs();
    ANN.forwardPropagate(input4);
    ANN.printOutputs();

    //train on the data set (XOR)
    int numIters = 10000;
    double learningRate = 0.1;
    for(int i = 0; i < numIters; i++){
        ANN.train(input1, correctOutput1, learningRate);
        ANN.train(input2, correctOutput2, learningRate);
        ANN.train(input3, correctOutput3, learningRate);
        ANN.train(input4, correctOutput4, learningRate);
    }

    std::cout << "\n\n*********  Post-training Prediction  **********" << std::endl;
    ANN.printWeightsByLayer();
    ANN.forwardPropagate(input1);
    ANN.printOutputs();
    ANN.forwardPropagate(input2);
    ANN.printOutputs();
    ANN.forwardPropagate(input3);
    ANN.printOutputs();
    ANN.forwardPropagate(input4);
    ANN.printOutputs();

    return 0;
}
