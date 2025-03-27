#include<iostream>

using namespace std;

/*
This was from the Data Structure & algorithm using c++ Zero To Mastery 2024 course.

This sums the elements in an array.

*/


int sumOfArray(int a[], int n) {
	if (n == 0) {
		return 0;
	}
		
	return a[0] + sumOfArray(a + 1, n - 1);
}

