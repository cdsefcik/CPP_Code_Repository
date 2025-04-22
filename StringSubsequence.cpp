#include <iostream>
#include <string>
using namespace std;

/*
The total number of subsequences of a string is 2^n, to include the character or not include the character.
Need to create a null string output = "" for the output for this function to work.
*/

void print_subs(string input, string output) {
	if (input.length() == 0) {
		cout << output << endl;
		return;
	}

	print_subs(input.substr(1), output + input[0]); //include part
	print_subs(input.substr(1), output); //Exclude part
	
}
