#include <iostream>
#include "matrix.h"
using std::cout;
using std::endl;
using std::out_of_range;

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


matrix::matrix(vector<vector<float>> _values)
{
	values = _values;
	rows = values.size();
	columns = values[0].size();
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

void matrix::scalar_multiply(float scalar)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			values[i][j] *= scalar;
		}
	}
}

void matrix::scalar_add(float scalar)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			values[i][j] += scalar;
		}
	}
}

void matrix::elem_multiply(matrix other)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			values[i][j] *= other.values[i][j];
		}
	}
}
void matrix::elem_add(matrix other)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			values[i][j] += other.values[i][j];
		}
	}
}

void matrix::transpose()
{
	int new_columns = rows;
	int new_rows = columns;
	vector<vector<float>> new_values;
	for (int i = 0; i < new_rows; i++)
	{
		vector<float> row;
		for (int j = 0; j < new_columns; j++)
		{
			row.push_back(values[j][i]);
		}
		new_values.push_back(row);
	}
	values = new_values;
	rows = new_rows;
	columns = new_columns;
}

void matrix::randomize()
{
	//TODO find a better random generation method, as this will (usually) create identical matrices
	srand((unsigned)time(0));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			values[i][j] = (float)(rand() % 10);
		}
	}
}

int matrix::compare_sizes(matrix other)
{
	if (other.rows == rows && other.columns == columns) return 0;
	if (other.rows == columns && other.columns == rows) return 1;
	return 2;
}

matrix matrix::multiply(matrix other)
{
	int comparison = compare_sizes(other);
	if (2 == comparison)
	{
		return zero_matrix();
	}
	if (0 == comparison)
	{
		other.transpose();
	}

	vector<vector<float>> result;

	for (int i = 0; i < rows; i++)
	{
		vector<float> row;
		for (int j = 0; j < other.columns; j++)
		{
			float sum = 0.0f;
			for (int k = 0; k < columns; k++)
			{
 				sum += values[i][k] * other.values[k][j];


				/**
				*
				*
				*
				*
				*
				*
				* Is the math right?
				* 
				*
				*
				*
				*
				*
				**/

			}
			row.push_back(sum);
		}
		result.push_back(row);
	}

	matrix out = matrix(result);

	if (0 == comparison)
	{
		other.transpose();
	}
	return out;
}

matrix matrix::zero_matrix()
{
	vector<float> pre;
	vector<vector<float>> out;
	pre.push_back(0.0f);
	out.push_back(pre);
	return matrix(out);
}