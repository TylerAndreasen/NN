#include <iostream>
#include "NN.h"
using std::cout;
using std::endl;

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

int main()
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
	srand(time(0));
	//vector<float> out = brain.feedforward(inputs);
	for (int i = 0; i < 1e5; i++)
	{
		int selection = rand() % 4;
		vector<float> toinput = training_set[selection].inputs;
		vector<float> tooutput = training_set[selection].outputs;
		brain.train(toinput, tooutput);
		//if (i % 1000 == 0)
		//{
		//	int temp = 0;
		//}
	}
	cout << "Complete Training" << endl;
	
	cout << "View of Learning" << endl;
	for (int i = 0; i < training_set.size(); i++)
	{
		auto display = [&brain](int i, xor_values val)
			{
				vector<float> thought = brain.feedforward(val.inputs);
				cout << "Input Pair for " << i << ":" << endl;
				cout << val.inputs[0] << ", " << val.inputs[1] << endl << endl;
				cout << "Correct Answer: " << endl;
				cout << val.outputs[0] << endl;
				cout << "Guess: " << endl;
				cout << std::fixed;
				cout << thought[0] << endl << endl << endl;

			};
		display(i, training_set[i]);
	}
	cout << "Experimentation Complete" << endl;
	return 0;
}

//int otherfunc(function<int()> func)
//{
//    func(69);
//    func(69);
//}
//
//int not3main()
//{
//    auto message = [](int num) {
//        cout << "Hello World!" << num << "\n";
//        };
//
//    otehrfunc(69);
//    return 0;
//}

