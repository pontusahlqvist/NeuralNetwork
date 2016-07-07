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
#include "OptionParser.h"

//This function takes the input string denoting the layer architecture and splits it on ',' and returns a vector of strings to be used by the ANN.
std::vector<std::string> splitIntoLayers(std::string input){
    std::vector<std::string> layerStrings;
    std::string tempString = "";
    for(int i = 0; i < input.length(); i++){
        if(input[i] == ','){
            layerStrings.push_back(tempString);
            tempString = "";
        } else{
            tempString += input[i];
        }
    }
    if(tempString != ""){ //just in case someone terminated the list of layers with a comma: "ss,s,sss,"
        layerStrings.push_back(tempString);
    }
    return layerStrings;
}

int main(int argc, const char * argv[]) {

    OptionParser optParser;
    optParser.add_option("-n", "Network configuration. This is a string of comma separated values each of which indicates the neuron configuration within a given layer. For example the string sss,st,l corresponds to three layers the first of which has 3 sigmoid units, the second of which has one sigmoid and one tanh unit, and a final output layer with a single linear unit.");
    if(!optParser.parse_options(argc, argv)){
        return 0; //exit program after either '-h' was passed or another error occurred.
    }

    //create the std::vector that will hold all the Neuron types. Each element of this list contains a string of character each of which identifies a type of neuron. For example, s = sigmoidal, e = exponential, l = linear, t = tanh.
    std::vector<std::string> neuronTypes;
    if(argc == 1){ //use default network if one isn't specified using the command line
        neuronTypes.push_back("ss");
        neuronTypes.push_back("s");
    } else{
        std::cout << optParser.getValue("-n");
        neuronTypes = splitIntoLayers(optParser.getValue("-n"));
    }

    //XOR example
    int numInputs = 2;
    NeuralNetwork ANN(neuronTypes, numInputs, false);

    std::vector<double> input1, input2, input3, input4;
    std::vector<double> correctOutput1, correctOutput2, correctOutput3, correctOutput4;
    std::vector< std::vector<double> > inputMatrix;
    std::vector< std::vector<double> > outputMatrix;

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

    inputMatrix.push_back(input1);
    inputMatrix.push_back(input2);
    inputMatrix.push_back(input3);
    inputMatrix.push_back(input4);
    outputMatrix.push_back(correctOutput1);
    outputMatrix.push_back(correctOutput2);
    outputMatrix.push_back(correctOutput3);
    outputMatrix.push_back(correctOutput4);
    
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
    double learningRate = 0.1;
    ANN.train(inputMatrix, outputMatrix, learningRate);

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
