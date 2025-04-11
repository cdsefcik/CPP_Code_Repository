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
