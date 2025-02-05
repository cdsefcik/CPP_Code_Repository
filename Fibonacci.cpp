#include<iostream>

using namespace std;

/*
* Fibonacci Numbers.
* Provides an example of programming with recursion. 
*/


int fib(int n) {
	//Base Case
	if (n == 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}

	//Recursive Case
	int smalloutput1 = fib(n-1);
	int smalloutput2 = fib(n - 2);

	//Calculation
	return smalloutput1 + smalloutput2;
}

int main() {

	int value;
	cout << "Enter when the series should end: ";
	cin >> value;

	cout<<"The value is: " << fib(value);


	return EXIT_SUCCESS;
}
