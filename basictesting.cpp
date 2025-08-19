#include <iostream>
#include "matrix.h"
using std::cout;
using std::endl;

int not1main()
{
	cout << "Init Matrix" << endl;
	// Initializes and Visualizes
	matrix reloaded = matrix(2, 3);
	reloaded.visualize_matrix();

	cout << endl << endl << "Randomize" << endl << endl;

	// Randomize
	reloaded.randomize();
	reloaded.visualize_matrix();

	// Size comparisons

	matrix keanu = matrix(2, 3);
	matrix dragon = matrix(3, 2);
	matrix champion = matrix(3, 3);
	matrix kvatch = matrix(4, 4);

	cout << endl << endl << "Size comparions" << endl;

	/*
	cout << "keanu: " << reloaded.compare_sizes(keanu) << endl;
	cout << "dragon: " << reloaded.compare_sizes(dragon) << endl;
	cout << "champion: " << reloaded.compare_sizes(champion) << endl;
	cout << "kvatch: " << reloaded.compare_sizes(kvatch) << endl;
	*/

	// Matrix Mult

	cout << endl << "Matrix Multiplication" << endl << "Initial" << endl;
	reloaded.visualize_matrix();

	cout << "Multiply by following matrix in correct orientation" << endl;
	dragon.randomize();
	dragon.visualize_matrix();

	matrix created = reloaded.multiply(dragon);

	cout << "Result" << endl;

	created.visualize_matrix();


	return 0;
}