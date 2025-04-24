#include <iostream>

using namespace std;


/*
Print all the permutations of a string.
*/

void printPermutation(char str[], int i=0) {
	if (str[i] == '\0') {
		cout << str << endl;
		return;
	}

	for (int j = i; str[j] != '\0'; j++) {
		swap(str[i], str[j]);
		printPermutation(str, i+1);
		swap(str[i], str[j]);
	}
}
