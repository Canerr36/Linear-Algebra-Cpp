#include <iostream>
#include "Matrix.h"


int main() {


	Matrix<double> A(3, 3);
	A(0, 0) = 25;
	A(0, 1) = 5;
	A(0, 2) = 1;
	A(1, 0) = 64;
	A(1, 1) = 8;
	A(1, 2) = 1;
	A(2, 0) = 144;
	A(2, 1) = 12;
	A(2, 2) = 1;

	
	////////////////////Deneme
	// skaler çarpým
	int n = 4;
	Matrix<double> F = A.Sklr(n);
	std::cout << F;
	std::cout << "\n\n";



	//A = L * U (Dolittle algoritmasý)
	Matrix<double> U = A.GetU();
	std::cout << "U :\n";
	std::cout << U;
	std::cout << "\n\n";

	std::cout << "L :\n";
	Matrix<double> L = A.GetL();
	std::cout << L;


}
