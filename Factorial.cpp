#include<iostream>

using namespace std;

/*
*Calculates the factorial of a number
*/


int main() {
	
	int number = 0;
	int total = 1;

	cout << "Enter the number: ";
	cin >> number;
	
	for (int i = number; i > 0; i--) {
    
		total = total * i;
	}
	
	cout << "The factorial is: " << total << endl;

	return EXIT_SUCCESS;
}
