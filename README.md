# NeuralNetwork
This is my own implementation of a simple feed forward neural network. The network is organized into layers where each layer consists of a set of neurons that can be of varying types. To facilitate this, I have created an abstract base class, Neuron, from which various types inherit. I have created Sigmoidal, Tanh, Linear, and Exponential neurons. I have also implemented backpropagation to allow for the calculation of derivatives and also training. In order to illustrate all of this, I have included the well-known XOR problem where a non-linear decision boundary has to be learned.

It’s written in C++ but I intend on adding a python wrapper which can read a config file where various options can be set (type of hill climbing method, the exact configuration of the various layers, etc.)

