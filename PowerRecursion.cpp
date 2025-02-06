#include<iostream>

using namespace std;

/*
* Calculate to the power of n, recursively
* Provides an example of programming with recursion. 
*/

int power(int x, int n) {

    //Base Case
	if (n == 0) {
		return 1;
	}

	//Recusive Case
	int smalloutput = power(x, n - 1);

	//calculation
	return x * smalloutput;
}

int main() {

	    int a;
		int b;
		cout << "Enter the base number: ";
		cin >> a;
		cout << endl;
		cout << "Enter the to the power of: ";
		cin >> b;
		cout << endl;

		cout << a << " To the power of " << b << " equals " << power(a, b) << endl;


	return EXIT_SUCCESS;
}
