//
//  main.cpp
//  NeuralNetwork
//
//  Created by Pontus Ahlqvist on 6/26/16.
//  Copyright (c) 2016 PontusAhlqvist. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
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

    std::vector< std::vector<double> > inputMatrix;
    std::vector< std::vector<double> > outputMatrix;
    std::vector<double> input1, input2, input3, input4;
    std::vector<double> correctOutput1, correctOutput2, correctOutput3, correctOutput4;
    std::ifstream trainingFile("/Users/Pontus/Desktop/Other Stuff/MLPrep/untitled folder 2/NeuralNetwork/NeuralNetwork/training.csv");
    std::string line;
    while(getline(trainingFile, line)){
        //structure is x_1,...,x_n y_1,y_2,...,y_m (comma and space separated)
        int spacePosition = (int)line.find(" ");
        int lastCommaPosition = -1;
        int nextCommaPosition = (int)line.find(",",lastCommaPosition+1);

        std::cout << "line from file: " << line << std::endl;

        //get inputs
        std::vector<double> input;
        while(nextCommaPosition != std::string::npos && nextCommaPosition < spacePosition){
            input.push_back(stod(line.substr(lastCommaPosition+1,nextCommaPosition)));
            lastCommaPosition = nextCommaPosition;
            nextCommaPosition = (int)line.find(",",nextCommaPosition+1);
            std::cout << input[input.size()-1] << " ";
        }
        input.push_back(stod(line.substr(lastCommaPosition+1,spacePosition)));
        std::cout << input[input.size()-1] << std::endl;

        //get outputs
        std::vector<double> output;
        lastCommaPosition = spacePosition;
        nextCommaPosition = (int)line.find(",",lastCommaPosition+1);
        while(nextCommaPosition != std::string::npos && nextCommaPosition < line.length()){
            output.push_back(stod(line.substr(lastCommaPosition+1,nextCommaPosition)));
            std::cout << output[output.size()-1] << " ";
        }
        output.push_back(stod(line.substr(lastCommaPosition+1)));
        std::cout << output[output.size()-1] << std::endl;

        //add these training data points to the training matrices
        inputMatrix.push_back(input);
        outputMatrix.push_back(output);
        std::cout << inputMatrix.size() << ", " << outputMatrix.size() << " - " << std::endl;
    }
    trainingFile.close();
    
    std::cout << "*********  Pre-training Prediction **********" << std::endl;
    ANN.printWeightsByLayer();
    for(int i = 0; i < inputMatrix.size(); i++){
        ANN.forwardPropagate(inputMatrix[i]);
        ANN.printOutputs();
    }
    //train on the data set (XOR)
    double learningRate = 0.1;
    ANN.train(inputMatrix, outputMatrix, learningRate);

    std::cout << "\n\n*********  Post-training Prediction  **********" << std::endl;
    ANN.printWeightsByLayer();
    for(int i = 0; i < inputMatrix.size(); i++){
        ANN.forwardPropagate(inputMatrix[i]);
        ANN.printOutputs();
    }

    return 0;
}
