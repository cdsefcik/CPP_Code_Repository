#include <iostream>

/*
*This program implements the linear search algorithm.
*Program is big(o) of n.
*/

int linearSearch(int* a, int n, int key) {

	for (int i = 0; i < n; i++) {
		if(a[i] == key){
			std::cout << "" << i << '\n';
			return i;
		}
	}
	return -1; //-1 because it is an invalid position.
};


int main() {

	std::cout << "Enter the number of elements: " << std::endl;
	int n;
	std::cin >> n;

	std::cout << "Enter the elements: " << std::endl;
	int *a = new int[n];

	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::cout << "Enter the key: " << std::endl;
	int key;
	std::cin >> key;

	int pos = linearSearch(a, n, key);
	if (pos == -1) {
		std::cout << "Key not found: " << std::endl;
	}
	else {
		std::cout << "The position is: " << pos << " " << std::endl;
	}

	delete a;

	return EXIT_SUCCESS;
};