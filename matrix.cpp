#include <iostream>
#include <random>
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
	update_dimensions();
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

matrix matrix::scalar_multiply(float& scalar)
{
	vector<vector<float>> temp;
	for (int i = 0; i < rows; i++)
	{
		vector<float> row;
		for (int j = 0; j < columns; j++)
		{
			row.push_back(values[i][j] * scalar);
		}
		temp.push_back(row);
	}
	return matrix(temp);
}

matrix matrix::scalar_add(float& scalar)
{
	vector<vector<float>> temp;
	for (int i = 0; i < rows; i++)
	{
		vector<float> row;
		for (int j = 0; j < columns; j++)
		{
			row.push_back(values[i][j] + scalar);
		}
		temp.push_back(row);
	}
	return matrix(temp);
}

matrix matrix::elem_multiply(matrix& other)
{
	vector<vector<float>> temp;
	for (int i = 0; i < rows; i++)
	{
		vector<float> row;
		for (int j = 0; j < columns; j++)
		{
			row.push_back(values[i][j] * other.values[i][j]);
		}
		temp.push_back(row);
	}
	return matrix(temp);
}

matrix matrix::elem_add(matrix& other)
{
	vector<vector<float>> temp;
	for (int i = 0; i < rows; i++)
	{
		vector<float> row;
		for (int j = 0; j < columns; j++)
		{
			row.push_back(values[i][j] + other.values[i][j]);
		}
		temp.push_back(row);
	}
	return matrix(temp);
}

matrix matrix::elem_sub(matrix& other)
{
	vector<vector<float>> temp;
	for (int i = 0; i < rows; i++)
	{
		vector<float> row;
		for (int j = 0; j < columns; j++)
		{
			row.push_back(values[i][j] - other.values[i][j]);
		}
		temp.push_back(row);
	}
	return matrix(temp);
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

matrix matrix::get_transposed_matrix()
{
	vector<vector<float>> new_values;
	for (int i = 0; i < columns; i++)
	{
		vector<float> row;
		for (int j = 0; j < rows; j++)
		{
			row.push_back(values[j][i]);
		}
		new_values.push_back(row);
	}
	return matrix(new_values);
}

void matrix::randomize()
{
	// Without seeding the random in this way,
	// the output is always the same.
	srand(time(0));
	std::random_device rd;
	std::mt19937 e2(rd());
	std::uniform_real_distribution<> dist(0, 1);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			values[i][j] = dist(e2) * 2.0f - 1.0f; // Range (-1,1)
		}
	}
}

matrix matrix::create_random_matrix(int _rows, int _columns)
{
	matrix out = matrix(_rows, _columns);
	out.randomize();
	return out;
}

int matrix::compare_sizes(matrix other)
{
	// Identical Shape
	if (other.rows == rows && other.columns == columns) return 0;
	// Transposed Shape
	if (other.rows == columns && other.columns == rows) return 1;
	return 2;
}

int matrix::can_be_multiplied(matrix& other)
{
	if (columns == other.rows) return 0;
	else return 1;
}

matrix matrix::multiply(matrix& other)
{
	int comparison = can_be_multiplied(other);

	if (comparison == 1)
	{
		return zero_matrix();
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
			}
			row.push_back(sum);
		}
		result.push_back(row);
	}

	matrix out = matrix(result);
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

void matrix::map(float(*elem_modify)(float&))
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			float temp = values[i][j];
			values[i][j] = elem_modify(temp);
		}
	}
}

matrix matrix::map(float(*elem_modify)(float&), matrix& in)
{
	vector<vector<float>> grid;
	for (int i = 0; i < in.rows; i++)
	{
		vector<float> row;
		for (int j = 0; j < in.columns; j++)
		{
			row.push_back(elem_modify(in.values[i][j]));
		}
		grid.push_back(row);
	}
	return matrix(grid);
}

float matrix::sigmoid(float in)
{
	return 1.0f / (1.0f + exp(-1.0f * in));
}

vector<float> matrix::fetch_output_from_matrix()
{
	vector<float> out;
	for (int i = 0; i < rows; i++) out.push_back(values[i][0]);
	return out;
}

void matrix::add_bias_elem()
{
	vector<float> anon{ 1.0f };
	values.push_back(anon);
	update_dimensions();
}

void matrix::update_dimensions()
{
	rows = values.size();
	columns = values[0].size();
}

int matrix::elem_compare(matrix other)
{
	if (0 != compare_sizes(other)) return -1;
	int difference_counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (values[i][j] != other.values[i][j]) difference_counter++;
		}
	}
	return difference_counter;
}