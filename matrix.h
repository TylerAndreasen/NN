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
	matrix scalar_multiply(float& scalar);
	matrix scalar_add(float& scalar);
	matrix elem_multiply(matrix& other);
	matrix elem_add(matrix& other);
	matrix elem_sub(matrix& other);
	/*Returns the number of elements which are different between
	this matrix and the argument.
	Returns -1 if the sizes are different.*/
	int elem_compare(matrix other);
	void transpose();
	matrix get_transposed_matrix();
	void randomize();
	static matrix create_random_matrix(int _rows, int _columns);
	/* Compares sizes of matrices.
	 * If dimensions are exactly the same, returns 0.
	 * If dimensions could be transposed, returns 1.
	 * If dimensions are not comparable, returns 2.*/
	int compare_sizes(matrix other);
	/*Returns 0 if this matrix can be safely multiplied by the supplied matrix.*/
	int can_be_multiplied(matrix& other);
	/* Will return a new matrix which is the result of Matrix multiplying
	 * the matrix the method is called on by the matrix supplied to the method.
	 * Note: Undefined behavior if used across threads, as supplied matrix may
	 * be transposed to allow multiplication to occur.*/
	matrix multiply(matrix& other);
	/*Returns a matrix with a single 0.*/
	static matrix zero_matrix();
	vector<float> fetch_output_from_matrix();
	void map(float(*elem_modify)(float&));
	static matrix map(float(*elem_modify)(float&), matrix& in);
	static float sigmoid(float in);
	void add_bias_elem();
	void update_dimensions();

}; 

