#include<iostream>

using namespace std;



bool isPresent(int a[], int n, int x) {
	if (n == 0) {
		return false;
	}
	if (a[0] == x) {
		return true;
	}

	return isPresent(a + 1, n - 1, x);
}
