#include <iostream>
#include<vector>

using namespace std;

/*
Prints every position with the value of x.
The second function saves every position in an array with the value of x.

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

void saveAllPos(int a[], int n, int x, int i, vector<int> &ans) {
	if (i == n) {
		return;
	}

	if (a[i] == x) {
		ans.push_back(i);
	}

	saveAllPos(a, n, x, i + 1, ans);

}
