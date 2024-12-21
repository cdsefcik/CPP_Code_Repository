#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

/*
*This demonstrates the use of errror handling with try, catch and throw. Creating the error object and throwing it.
*
*
*/

inline void keep_window_open() {
	char ch; cin >> ch;
}

class Bad_area{};

int area(int length, int width) {
	if (length <= 0 || width <= 0) throw Bad_area();
	return length * width;
}

int main() {
	try {
		int x = -1;
		int y = 2;
		int z = 4;
		int area1 = area(x, y);
		return EXIT_SUCCESS;
	}
	catch (Bad_area) {
		cerr << "Oops! bad arguments to area()\n"; //The cerr is used as output for errors. 
		return EXIT_FAILURE;
	}	
};
