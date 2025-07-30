#include <vector>
using std::vector;
#pragma once
class matrix
{
private:
	int rows, columns;
	vector<vector<float>> values;

public:
	matrix(int _rows, int _columns);
	void visualize_matrix();
	void scalar_multiply(float scalar);
};

