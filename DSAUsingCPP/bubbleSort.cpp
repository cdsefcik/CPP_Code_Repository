#include<iostream>
using namespace std;

/*
This was from the Data Structure & algorithm using c++ Zero To Mastery 2024 course.

The parameters are an array and the size of the array.

The BIG O is n^2.

*/


void bubbleSort(int a[], int n) {

	for (int count = 1; count <= n - 1; count++) {
		for (int j = 0; j <= n - 2; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}