/*
Given an image represented by an N x N matrix. Where each pixel in the image is represented by an integer, write a method
to rotate the image by 90 degrees. Can you do this in place?
*/


#include<iostream>
#include<vector>
#include<random>

std::vector<std::vector<int>> vector90(std::vector<std::vector<int>>& matrix) {




	return matrix;
}

int main() {

	std::vector<std::vector<int>> matrix;

	std::cout << "Enter the size of the matrix NxN between 1 and 100: ";
	int size = 0;
	std::cin >> size;

	if (size <= 1 || size > 100) {
		std::cerr<<"Size is out of bounds: ";
	}

	//Generate the user matrix:
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 100);

	for (int i = 0; i < size; i++) {
		std::vector<int> row;
		for (int j = 0; j < size; j++) {
			row.push_back(dis(gen));
		}
		matrix.push_back(row);
	}

	//Print the matrix
	for (const auto& row : matrix) {
		for (const auto& column : row) {
			std::cout << column << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}


