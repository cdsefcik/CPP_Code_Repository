#include <iostream>

using namespace std;


/*
Converts a character string to an integer.
Note: Character - Character is an integer.
Can only contain 9 characters.
*/

int length(char input[]) {
	if (input[0] == '\0') {
		return 0;
	}
	return 1 + length(input + 1);
}

int convertStringToInt(char str[], int n) {

	if (n == 0) {
		return 0;
	}
	int smallAns = convertStringToInt(str, n - 1);
	int lastDigit = str[n - 1] - '0';
	int ans = smallAns * 10 + lastDigit;
	return ans;
}
