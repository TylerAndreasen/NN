#include "NN.h"
#include <vector>
using std::vector;
NN::NN(int inputs, int hiddens, int outputs)
{
	// Assumes layer counts are not 0
	for (int i = 0; i < hiddens; i++)
	{
		hiddenlayer.push_back(neuron(inputs));
	}
	for (int i = 0; i < outputs; i++)
	{
		outputlayer.push_back(neuron(hiddens));
	}
}
vector<float> NN::feedforward(vector<float> inputvalues)
{
	vector<float> hiddensums;
	for (int i = 0; i < hiddenlayer.size(); i++)
	{
		hiddensums.push_back(hiddenlayer[i].guess(inputvalues));
	}
	vector<float> outputsums;
	for (int i = 0; i < outputlayer.size(); i++)
	{
		outputsums.push_back(outputlayer[i].guess(hiddensums));
	}
	return outputsums;
}
//vector<float> NN::train(vector<float> inputvlaues, vector<float> correctoutput)
//{
//	// TODO STUB
//}