#include<iostream>
#include<string>

using namespace std;

/*
*Sum numbers using recursion
* 
*/

int sum(int number);


int main() {

	int number = 0;
	int result = 0;
	cout << "Enter a number to sum, every preceding number, up to that number: ";
	cin >> number;

	result = sum(number);

	cout << "\n";
	cout << result;
	
	return EXIT_SUCCESS;
}

int sum(int number) {
	int result = 0;
	if (number == 0) {
		return result;
	}
	else {
		result = (number + sum(number - 1));
	}

}
