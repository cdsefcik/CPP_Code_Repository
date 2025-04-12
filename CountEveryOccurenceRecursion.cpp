#include <iostream>

using namespace std;

/*
Counts the occurences of an element.
a[] = array,
*/

void count(int a[], int n, int x, int i, int& ans) {
	if (i == n) {
		return;
}
	if (a[i] == x) {
		ans++;
}

	count(a, n, x, i + 1, ans);

}

int count2(int a[], int n, int x, int i) {
	if (i == n) {
		return 0;
	}
	if (a[i] == x) {
		return 1 + count2(a, n, x, i + 1);
	}
	else {
		return count2(a, n, x, i + 1);
	}
}
