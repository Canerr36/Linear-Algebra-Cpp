#include <iostream>
#include <memory>





int main() {

	int size;
	std::cout << "Matrisin Boyutunu Giriniz :";
	std::cin >> size;

	// doðru kullaným
	auto DinamikDizi = std::make_unique<std::unique_ptr<int[]>[]>(size);
	for (int i = 0; i < size; i++) {
		DinamikDizi[i] = std::make_unique<int[]>(size);
	}

	auto DinamikDizi2 = std::make_unique<std::unique_ptr<int[]>[]>(size);
	for (int i = 0; i < size; i++) {
		DinamikDizi2[i] = std::make_unique<int[]>(size);
	}

	auto DinamikDizi3 = std::make_unique<std::unique_ptr<int[]>[]>(size);
	for (int i = 0; i < size; i++) {
		DinamikDizi3[i] = std::make_unique<int[]>(size);
	}



	// A matrisi
	std::cout << "A matrisinin elemanlarini giriniz " << std::endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << "a" << (i + 1) << (j + 1) << " :";
			std::cin >> DinamikDizi[i][j];
		}
	}

	// B matrisi
	std::cout << "B matrisinin elemanlarini giriniz " << std::endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << "b" << (i + 1) << (j + 1) << " :";
			std::cin >> DinamikDizi2[i][j];
		}
	}



	// matris çarpýmý
	for (int i = 0; i < size; i++) {

		for (int k = 0; k < size; k++) {

			for (int j = 0; j < size; j++) {

				DinamikDizi3[i][k] += DinamikDizi[i][j] * DinamikDizi2[j][k];
			}

		}


	}
	std::cout << "\n\n";


	// sonuc matrisi
	std::cout << "Sonuc \n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << DinamikDizi3[i][j] << "  ";
		}
		std::cout << "\n";
	}




}
