#include <iostream>
#include "matrix.h"
using std::cout;
using std::endl;

matrix::matrix(int _rows, int _columns)
{
	rows = _rows;
	columns = _columns;
	for (int i = 0; i < rows; i++)
	{
		vector<float> row;
		for (int j = 0; j < columns; j++)
		{
			row.push_back(0.0f);
		}
		values.push_back(row);
	}
}

void matrix::visualize_matrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << values[i][j] << " ";
		}
		cout << endl;
	}
}