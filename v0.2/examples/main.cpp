#include <iostream>
#include "Matrix.h"



int main() {

	//denemeler 
	Matrix<int> A(2, 2);
	Matrix<int> B(2, 2);
	A(0, 0) = 1;
	A(0, 1) = 2;
	A(1, 0) = 3;
	A(1, 1) = 4;

	B(0, 0) = 4;
	B(0, 1) = 3;
	B(1, 0) = 2;
	B(1, 1) = 1;

	
	Matrix<int> C = A * B;
	Matrix<int> D = A + B;
	Matrix<int> E = A - B;

	std::cout << C << std::endl;
	std::cout << D << std::endl;
	std::cout << E << std::endl;



}