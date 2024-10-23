#include<iostream>
#include<string>
#include<fstream>

using namespace std;

/*
* Exception in C++.
* Used for Runtime Errors.
* Three parts, Try, Throw and Catch. Throw, throws the error, catch, catches the thrown error.
* Can have many different catch blocks.
* Throw is always used inside the try block.
* This program gives an example of how to try, throw and catch errors.
*/


int main() {

	int num1 = 0, num2 = 0, total = 0;
	
	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

	//Use a try block
	try {
	
		if (num2 == 0) {
			string err = "Number divided by 0";
			throw err;
		}
		else {
			//Operation
			total = num1 / num2;
			cout << "Output is " << total;
		}
	
     }
	catch(int x){
		cout << "Exception is divide by zero" << endl;
	 }

	catch (string y) {
		cout << y;
	}
	catch (...) { //Generic catch block.
		cout << "Error Occured";
	}
	
    return EXIT_SUCCESS;
}

