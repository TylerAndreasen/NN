#include "neuron.h"
#include <time.h>

neuron::neuron(int _weight_count)
{
	srand((unsigned)time(0));
	// i <= _weight_count to account for bias
	for (int i = 0; i < _weight_count + 1; i++)
	{
		weights.push_back(randWeight());
	}
}

float neuron::guess(vector<float> inputs)
{
	float sum = 0;
	for (int i = 0; i < inputs.size(); i++)
	{
		sum += inputs.at(i) * weights.at(i);
	}
	// Add Weighted Bias
	sum += weights.back();
	return activation(sum);
}

int neuron::activation(float pre_activation)
{
	// TODO STUB
	return 0;
}

//int neuron::train(vector<float> inputs, int screenWidth, int screenHeight)
//{
//	// TODO STUB
//	return 0;
//}

// Based on this SO answer
// https://stackoverflow.com/questions/686353/random-float-number-generation/686373#686373
float neuron::randWeight()
{
	return LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO)));
}