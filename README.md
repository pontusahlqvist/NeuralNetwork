# NeuralNetwork
This is my own implementation of a simple feed forward neural network. The network is organized into layers where each layer consists of a set of neurons that can be of varying types. To facilitate this, I have created an abstract base class, Neuron, from which various types inherit. At this point I just have a sigmoid one, but nothing precludes the creation of other types (tanh, linear, perceptron, …). 

It’s written in C++ but I intend on adding a python wrapper which can read a config file where various options can be set (type of hill climbing method, the exact configuration of the various layers, etc.)

