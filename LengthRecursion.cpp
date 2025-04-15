#include<iostream>

using namespace std;

int lengthRecursion(char input[]) {
	if (input[0] == '\0') {
		return 0;
	}

	int smallength = lengthRecursion(input + 1);
	return 1 + smallength;

}
