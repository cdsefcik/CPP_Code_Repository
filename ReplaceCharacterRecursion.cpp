#include<iostream>

using namespace std;

/*
This function replaces all characters with a, with x, recursively.
*/

void replaceCharacter(char input[]) {
	if (input[0] == '\0') {
		return;
	}

	if (input[0] == 'a') {
		input[0] = 'x';
	}

	replaceCharacter(input + 1);

}
