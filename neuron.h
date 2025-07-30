#include <vector>
using std::vector;
#pragma once
class neuron
{
private:
	vector<float> weights;
	const float LEARNING_RATE = 0.1f;
	const float LO = -1.0f;
	const float HI = 1.0f;
	float randWeight();
	int activation(float pre_activation);
public:
	/* Constructor for the neuron class. 
	 * Int parameter defines the number of external inputs (IE, don't add 1 for the bias).*/
	neuron(int _weight_count);
	float guess(vector<float> inputs);
	//int train(vector<float> inputs, int screenWidth, int screenHeight);
};

