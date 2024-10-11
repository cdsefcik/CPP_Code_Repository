#include<iostream>

using namespace std;

/*
*Print star patterns with for loop.
*/


int main() {
	
	int x = 0, y = 0;

	for (x = 0; x < 5; x++) {
		for (y = 0; y < (x + 1); y++) {
			cout << "*";
		}
		cout << endl;
	}

	cout << "\n";
	x = 0, y = 0;

	for (x = 0; x < 5; x++) {
		for (y = 5; y > x; y--) {
			cout << "*";
		}
		cout << endl;
	}

	return EXIT_SUCCESS;
}
