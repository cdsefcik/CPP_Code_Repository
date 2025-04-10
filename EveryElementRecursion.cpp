#include <iostream>

using namespace std;

/*
Prints every element in an array.

*/


void printAllPos(int a[], int n, int x, int i) {
	if (i == n) {
		return;
	}

	if (a[i] == x) {
		cout << i << " ";
	}

	printAllPos(a, n, x, i+1);

}
