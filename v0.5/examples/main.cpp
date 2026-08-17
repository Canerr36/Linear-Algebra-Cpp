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
	Matrix<double> b(3, 1);
	b(0, 0) = 1;
	b(1, 0) = 3;
	b(2, 0) = 7;



	////////////////////////////Deneme 
	//A = Q * R ayrýþmasý 
	auto qr = A.qrDecompose();           
	Matrix<double> Q = qr.first;
	Matrix<double> R = qr.second;

	std::cout << "Q :\n" << Q << "\n";
	std::cout << "R :\n" << R << "\n\n\n";


	// Gauss eliminasyonu
	Matrix<double> G = A.gaussianEliminate();
	std::cout << "G :\n";
	std::cout << G << "\n\n";
	//Ax=b		x i bulma
	Matrix<double> L = A.solve(b);
	std::cout << "L :\n";
	std::cout << L << "\n\n";



	//Bir matrisin rankýný bulma
	int a = A.rank();
	std::cout << "Rank A :" << a;


}
