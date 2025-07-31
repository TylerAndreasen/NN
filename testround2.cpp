#include <iostream>
#include "matrix.h"
using std::cout;
using std::endl;
int main()
{
	matrix first = matrix(3, 3);
	matrix second = matrix(3, 3);

	cout << "First" << endl << endl;
	first.randomize();
	first.visualize_matrix();

	cout << "Second" << endl << endl;
	second.randomize();
	second.visualize_matrix();

	matrix result = first.multiply(second);

	cout << "First times Second result" << endl << endl;

	result.visualize_matrix();

	return 0;
}