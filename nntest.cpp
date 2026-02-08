#include <iostream>
#include <string>
#include "NN.h"
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::fwrite;
//using std::c_str;

//const static int TRAINING_ITERATIONS = 1e4;

enum OUTPUT_OPTIONS {STD, FILE_O};

static int output_destination = STD;

void printvec(vector<float> in)
{
	for (int i = 0; i < in.size(); i++)
	{
		cout << in[i] << ", ";
 	}
	cout << endl;
}

struct xor_values
{
	vector<float> inputs;
	vector<float> outputs;
};

int main(int TRAINING_ITERATIONS, float learning_rate)
{
	cout << "Enter Main" << endl;
	NN brain = NN(2, 2, 1);
	cout << "Create Brain" << endl;

	xor_values a;
	a.inputs = { 0.0f, 0.0f };
	a.outputs = { 0.0f };
	
	xor_values b;
	b.inputs = { 0.0f, 1.0f };
	b.outputs = { 1.0f };

	xor_values c;
	c.inputs = { 1.0f, 0.0f };
	c.outputs = { 1.0f };

	xor_values d;
	d.inputs = { 1.0f, 1.0f };
	d.outputs = { 0.0f };

	vector<xor_values> training_set{ a,b,c,d };
	cout << "Create Training Data" << endl;

	cout << "Begin Training" << endl;
	srand(0);
	//vector<float> out = brain.feedforward(inputs);
	for (int i = 0; i < TRAINING_ITERATIONS; i++)
	{
		int selection = rand() % 4;
		vector<float> toinput = training_set[selection].inputs;
		vector<float> tooutput = training_set[selection].outputs;
		brain.train(toinput, tooutput, learning_rate);
		//if (i % 1000 == 0)
		//{
		//	int temp = 0;
		//}
	}
	cout << "Complete Training" << endl;
	
	cout << "View of Learning" << endl;
	FILE* fp;
	if (output_destination == FILE_O)
	{
		string temp = to_string(time(0));
		const char* fname = temp.c_str();
		fp = fopen(fname, "w");
	}
	for (int i = 0; i < training_set.size(); i++)
	{
		auto display = [&brain, &fp](int i, xor_values val)
			{
				vector<float> thought = brain.feedforward(val.inputs);
				if (output_destination == STD || !fp)
				{
					cout << "Input Pair for " << i << ":" << endl;
					cout << val.inputs[0] << ", " << val.inputs[1] << endl << endl;
					cout << "Correct Answer: " << endl;
					cout << val.outputs[0] << endl;
					cout << "Guess: " << endl;
					cout << std::fixed;
					cout << thought[0] << endl << endl << endl;
				}
				//else
				//{
				//	fwrite(, , , fp);
				//}
			};
		display(i, training_set[i]);
	}
	cout << "Experimentation Complete" << endl;
	char t;
	std::cin >> t;
	return 0;
}