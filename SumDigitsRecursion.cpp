#include<iostream>

using namespace std;

/*
* Sum all the digits using recursion.
* Provides an example of programming with recursion. 
*/

int sum(int n) {

	//Base case
	if (n == 0) {
		return 0;
	}

	//Recursive Case
	int smallAns = sum(n / 10);

	//Calculation
	int last_digit = n % 10;
	return smallAns + last_digit;
    
}


int main() {

	    int a;
		cout << "Enter the number: ";
		cin >> a;
		cout << sum(a);
		cout << endl;


	return EXIT_SUCCESS;
}
