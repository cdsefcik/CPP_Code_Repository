#include <iostream>
#include <string>
#include <vector>
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

void store_subs(string input, string output, vector<string> &v) {
	if (input.length() == 0) {
		v.push_back(output);
		return;
	}

	store_subs(input.substr(1), output + input[0], v); //include part
	store_subs(input.substr(1), output,v); //Exclude part

}


