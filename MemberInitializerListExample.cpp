#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

/*
*This implements class token.
*Instructs how to create a class using "Member Initializer List", starting with the semi colan.
*/

inline void keep_window_open() {
	char ch; cin >> ch;
}


class Token {
public:
	char kind;
	double value;
	
	Token(char ch) :kind(ch), value(0) { //Create an object Token with kind being initialized from ch and value being initialized to zero.

	}

	Token(char ch, double val) :kind(ch), value(val) { //Create an object with kind being initialized from ch and value initialized from val.
	}
};

int main() {

	return EXIT_SUCCESS;
}
