#include "NN.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "matrix.h"
using std::vector;
using std::exp;
using std::cout;
using std::endl;


const float NN::LEARNING_RATE = 1e-6;


NN::NN(int _inputs, int _hiddens, int _outputs)
	: weights_I_H(_hiddens, _inputs + 1),
		weights_H_O(_outputs, _hiddens + 1)
{
	weights_I_H.randomize();
	weights_H_O.randomize();
	inputs = _inputs;
	hiddens = _hiddens;
	outputs = _outputs;
}

vector<float> NN::feedforward(vector<float>& inputvalues)
{
	// <Input Feed Forward>
	matrix inputmatrix = input_values_to_useable_matrix(inputvalues);

	inputmatrix.add_bias_elem();

	//matrix transposed_input = inputmatrix.get_transposed_matrix();

	// </Input Feed Forward>

	// Calculate Hidden Layer activation
	matrix hidden = weights_I_H.multiply(inputmatrix);
	
	// <Hidden Feed Forward>
	//activation(hidden, sigmoid);
	hidden.map(sigmoid);

	hidden.add_bias_elem();

	//matrix transposed_hidden = hidden.get_transposed_matrix();
	// </Hidden Feed Forward>

	// Calculate Output activation
	matrix guess = weights_H_O.multiply(hidden);



	//last_feed_forward_output = guess.fetch_output_from_matrix();

	return guess.fetch_output_from_matrix();
}

void NN::train(vector<float>& inputvalues, vector<float>& targets, float learning_rate)
{
	//cout << "Call train()" << endl;
	// <Input Feed Forward>
	matrix inputmatrix = input_values_to_useable_matrix(inputvalues);

	inputmatrix.add_bias_elem();

	matrix transposed_input = inputmatrix.get_transposed_matrix();
	//cout << "Complete Input Layer Calculations" << endl;
	// </Input Feed Forward>

	// Calculate Hidden Layer activation
	matrix hidden = weights_I_H.multiply(inputmatrix);
	//if (hidden.compare_sizes(matrix::zero_matrix()))
	//{
	//	cout << "Guess Matrix is single zero" << endl;
	//}

	// <Hidden Feed Forward>
	//activation(hidden, sigmoid);
	hidden.map(sigmoid);

	hidden.add_bias_elem();

	matrix transposed_hidden = hidden.get_transposed_matrix();
	//cout << "Complete Hidden Layer Calculations" << endl;
	// </Hidden Feed Forward>

	// Calculate Output activation
	matrix guess = weights_H_O.multiply(hidden);
	if (0 == guess.elem_compare(matrix::zero_matrix()))
	{
		cout << "Guess Matrix is single zero" << endl;
	}
	//cout << "Calculated Guess" << endl;
	// Do I need a copy of guess?


	

	// <Step 1, Calculate Error>
	// Generate Target Matrix
	matrix targetmatrix = input_values_to_useable_matrix(targets);

	// Calculate Errors from Hidden to Output
	matrix error_H_O = targetmatrix.elem_sub(guess);


	// Calculate Errors from Input to Hidden
	matrix weights_HOT = weights_H_O.get_transposed_matrix();
	matrix error_I_H = weights_HOT.multiply(error_H_O);
	//cout << "Completed Step 1" << endl;
	// </Step 1>

	// <Step 2, Scale error by the Learning Rate>
	// Scale by learning rate, unfortunate implementation.
	float LR_COPY = learning_rate;
	error_H_O = error_H_O.scalar_multiply(LR_COPY);
	error_I_H = error_I_H.scalar_multiply(LR_COPY);
	//cout << "Completed Step 2" << endl;
	// </Step 2>

	// <Step 3, Calculate Gradient>

	// Assign the already sigmoided guess to the derivative of itself
	matrix dsigmoid_guess = matrix::map(dsigmoid, guess);
	matrix dsigmoid_hidden = matrix::map(dsigmoid, hidden);


	matrix step3_guess = error_H_O.elem_multiply(dsigmoid_guess);
	matrix step3_hidden = error_I_H.elem_multiply(dsigmoid_hidden);
	//cout << "Completed Step 3" << endl;
	// </Step 3>

	// <Step 4, Multiply by Transposed Weights>
	matrix deltaWHO = step3_guess.multiply(transposed_hidden);
	matrix deltaWIH = step3_hidden.multiply(transposed_input);

	//cout << "Completed Step 4" << endl;
	// </Step 4>

	// <Step 5, Change Weights by Deltas>

	weights_H_O = weights_H_O.elem_add(deltaWHO);
	weights_I_H = weights_I_H.elem_add(deltaWIH);

/*	weights_H_O.map(sigmoid);
	weights_I_H.map(sigmoid);
	*///cout << "Completed Step 5" << endl;
	// </Step 5>
}

vector<float> NN::strip_last_value(vector<float>& in)
{
	if (in.size() == 1) return in;
	vector<float> out;
	for (int i = 0; i < in.size() - 1; i++) out.push_back(in[i]);
	return out;
}

//void NN::activation(matrix& toActivate, float(*callable)(float))
//{
//	toActivate.map(callable);
//}

float NN::sigmoid(float& in)
{
	return 1.0f / (1.0f + exp(-1.0f * in));
}

float NN::dsigmoid(float& in)
{
	return in * (1.0f - in);
}

matrix NN::input_values_to_useable_matrix(vector<float>& in)
{
	vector<vector<float>> temp;
	for (int i = 0; i < in.size(); i++)
	{
		vector<float> row{ in[i] };
		temp.push_back(row);
	}
	return matrix(temp);
}