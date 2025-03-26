#include<iostream>
using namespace std;

/*
This was from the Data Structure & algorithm using c++ Zero To Mastery 2024 course.

isSorted using recursion. Returns a boolean value if the array is sorted or not.

*/

bool isSorted(int a[], int n) {
	if (n == 0 || n == 1) {
		return true;
	}

	if (a[0] > a[1]) {
		return false;
	}

	bool isSmallerSorted = isSorted(a + 1, n - 1);

	return isSmallerSorted;
}
