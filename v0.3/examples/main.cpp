#include <iostream>
#include "Matrix.h"


int main() {

	
	Matrix<int> A(2, 2);
	A(0, 0) = 1;
	A(0, 1) = 2;
	A(1, 0) = 3;
	A(1, 1) = 4;

	
	// transpoz örnek
	Matrix<int> At = A.Trans();
	std::cout << A << "\n";
	std::cout << At << "\n";


	// Determinant örnek
	int Ad = A.Det();
	std::cout << Ad;


}
