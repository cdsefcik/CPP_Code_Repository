#include<iostream>

using namespace std;

/*
* Print the numbers one to n, recursively.
* Provides an example of programming with recursion. 
*/

void print(int n) {

    //Base Case
	if (n == 0) {
		return;
	}

	//Recusive Case
	print(n- 1);

	//Output
	cout << " " << n;
	return;
}

void print2(int n) {

	//Base Case
	if (n == 0) {
		return;
	}

	//Output
	cout << " " << n;

	//Recusive Case
	print2(n - 1);

	
}

int main() {

	    int a;
		cout << "Enter the print to number: ";
		cin >> a;
		cout << endl;

		cout << "The numbers are: " << endl;
		print(a);
		cout << endl;
		print2(a);


	return EXIT_SUCCESS;
}
