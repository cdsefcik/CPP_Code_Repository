#include <iostream>

using namespace std;

/*
The first function prints the number of steps required for the tower of hanoi
The second function prints the steps in the tower of hanoi.

For the second section, A is the source, C is the destination step and B is the helper part.
*/

int toh(int n) {
	if (n == 0) {
		return 0;
	}

	return toh(n - 1) + 1 + toh(n - 1);
}


void printSteps(int n, char s, char d, char h) {
	if (n == 0) {
		return;
	}

	printSteps(n - 1, s, h, d);
	cout << "Moving disk " << "From " << s << " To " << d << endl;
	printSteps(n - 1, h, d, s);
}


