#include<iostream>;

using namespace std;

/*
The first function prints all the elements in the array.
The second function prints all the elements in the array in reverse.
*/

void print(char input[]) {
	if (input[0] == '\0') {
		return;
	}

	cout << input[0];

	print(input + 1);
}

void revPrint(char input[]) {
	if (input[0] == '\0') {
		return;
	}

	revPrint(input + 1);
	cout << input[0];
}
