#include <iostream>
#include <vector>
#include "matrix.h"
using std::cout;
using std::endl;
using std::vector;

vector<vector<float>> genvvf(int rows, int columns, float value)
{
	vector<vector<float>> out;
	for (int i = 0; i < rows; i++)
	{
		vector<float> row;
		for (int j = 0; j < columns; j++)
		{
			row.push_back(value);
		}
		out.push_back(row);
	}
	return out;
}

int notmain5()
{
	matrix onebyone{ 1, 1 };
	matrix zero = matrix::zero_matrix();

	cout << "TEST:: Compare two Zero Matrices:" << endl << "\tOutput: " << onebyone.elem_compare(zero) << endl << endl;
	// Should be 0

	vector<float> temp{ 1.0f };
	vector<vector<float>> values{ temp };
	onebyone = { values };

	cout << "TEST:: Compare One Matrix to Zero Matrix:" << endl << "\tOutput: " << onebyone.elem_compare(zero) << endl << endl;
	// Should be 1

	matrix twos = genvvf(2, 2, 2);
	cout << "TEST:: Compare Twos Matrix to Zero Matrix:" << endl << "\tOutput: " << twos.elem_compare(zero) << endl << endl;
	// Should be -1

	matrix threes = genvvf(2, 2, 3);
	cout << "TEST:: Compare Twos Matrix to Threes Matrix:" << endl << "\tOutput: " << twos.elem_compare(threes) << endl << endl;
	// Should be 4

	matrix fives = twos.elem_add(threes);

	matrix fullfives = genvvf(2, 2, 5);
	cout << "TEST:: Compare Fives Matrix to sum of Twos and Threes Matrix:" << endl << "\tOutput: " << fullfives.elem_compare(fives) << endl << endl;
	// Should be 0

	matrix arbitrary = matrix::create_random_matrix(2, 2);
	matrix aplustwo = arbitrary.elem_add(twos);

	cout << "TEST:: Compare Arbitrary Matrix to sum of Itself and Twos Matrix:" << endl << "\tOutput: " << arbitrary.elem_compare(aplustwo) << endl << endl;
	// Should be 4

	matrix tens = twos.elem_multiply(fives);
	matrix fulltens = genvvf(2, 2, 10);
	cout << "TEST:: Compare Tens Matrix to product of Fives and Twos Matrix:" << endl << "\tOutput: " << fulltens.elem_compare(tens) << endl << endl;
	// Should be 0


	vector<float> m1r1{ 1,2,3 };
	vector<float> m1r2{ 4,5,6 };
	vector<vector<float>> vv1{ m1r1,m1r2 };
	matrix m1(vv1);

	vector<float> m2r1{ 7,8 };
	vector<float> m2r2{ 9,10 };
	vector<float> m2r3{ 11,12 };

	vector<vector<float>> vv2{ m2r1,m2r2,m2r3 };
	matrix m2(vv2);

	matrix product = m1.multiply(m2);

	vector<float> m3r1{ 58,64 };
	vector<float> m3r2{ 139,154 };
	vector<vector<float>> vv3{ m3r1,m3r2 };
	matrix correct(vv3);
	cout << "TEST:: Compare Matrix of product of 1-6 on a 2x3 times 7-12 on a 3x2 to the Correct Product Matrix:" << endl << "\tOutput: " << product.elem_compare(correct) << endl << endl;
	// Should be 0

	cout << "TEST:: Compare Matrix of product of 1-6 on a 2x3 times 7-12 on a 3x2 to the 1-6 Matrix:" << endl << "\tOutput: " << product.elem_compare(m1) << endl << endl;
	// Should be -1

	return 0;
}