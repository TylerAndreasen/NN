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
	matrix(vector<vector<float>> _values);
	void visualize_matrix();
	void scalar_multiply(float scalar);
	void scalar_add(float scalar);
	void elem_multiply(matrix other);
	void elem_add(matrix other);
	void transpose();
	void randomize();
	/* Compares sizes of matrices.
	 * If dimensions are exactly the same, returns 0.
	 * If dimensions could be transposed, returns 1.
	 * If dimensions are not comparable, returns 2.*/
	int compare_sizes(matrix other);
	/* Will return a new matrix which is the result of Matrix multiplying
	 * the matrix the method is called on by the matrix supplied to the method.
	 * Note: Undefined behavior if used across threads, as supplied matrix may
	 * be transposed to allow multiplication to occur.*/
	matrix multiply(matrix other);
	/*Returns a matrix with a single 0.*/
	matrix zero_matrix();

};

