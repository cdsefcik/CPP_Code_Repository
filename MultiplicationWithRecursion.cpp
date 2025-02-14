#include<iostream>

using namespace std;

/*
* Multiplication using recursion.
* Provides an example of programming with recursion. 
*/

int multiply(int m, int n) {

	//Base case
	if (n == 0) {
		return 0;
	}

	//Recursive Case
	int smallAns = multiply(m, n - 1);

	//Calculation
	return smallAns + m;
    
}


int main() {

	    int a;
		cout << "Enter the number: ";
		cin >> a;
		
		int b;
		cout << "Enter the second number";
		cin >> b;

		cout << multiply(a, b);

}
