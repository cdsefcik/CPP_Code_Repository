#include <iostream>

using namespace std;

/*
Counts the number of ways that we can count to a number. Exe: 3 is 1+1+1, 2+1, 3
*/

int countWays(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}

	if (n == 2) {
		return 2;
	}

	return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}
