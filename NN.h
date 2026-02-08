#include <vector>
#include <functional>
#include "matrix.h"
using std::vector;
using std::function;
#pragma once
class NN
{
private:
	int inputs, hiddens, outputs;
	matrix weights_I_H, weights_H_O;
	vector<float> last_feed_forward_output;
	static const float LEARNING_RATE;
public:
	NN(int _inputs, int _hiddens, int _outputs);
	vector<float> feedforward(vector<float>& inputvalues);
	void train(vector<float> &inputvalues, vector<float> &correctoutput, float learning_rate);
	//void activation(matrix& toActivate, float(*callable)(float));
	static float sigmoid(float& in);
	static float dsigmoid(float& in);
	static matrix input_values_to_useable_matrix(vector<float>& in);
	vector<float> strip_last_value(vector<float>& in);
};

