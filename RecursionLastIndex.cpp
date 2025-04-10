#include <iostream>

using namespace std;

/*
Finds the index of the element if found in the array.

*/


int lastIndex(int a[], int n, int x, int i) {
	if (i == -1) {
		return -3;
	}

	if (a[i] == x) {
		return i;
	}

	return lastIndex(a, n, x, i - 1);
}

int lastIndex2(int a[], int n, int x) {
	if (n == 0) {
		return -3;
	}

	if (a[n-1] == x) {
		return n-1;
	}

	return lastIndex2(a, n-1, x);
}
