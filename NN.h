#include <vector>
#include "neuron.h"
using std::vector;
#pragma once
class NN
{
private:
	vector<neuron> hiddenlayer, outputlayer;
public:
	NN(int inputs, int hiddens, int outputs);
	vector<float> feedforward(vector<float> inputvalues);
	vector<float> train(vector<float> inputvlaues, vector<float> correctoutput);
};

