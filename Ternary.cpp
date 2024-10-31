#include<iostream>
#include<string>
#include<thread>

using namespace std;

/*
* Ternary operator example.
* Return the largest value.
*/

int getInt() {
	int value = 0;
	cout << "Enter an integer: ";
		cin >> value;
		cout << "\n";
		return value;
}

int main()
{
	int x{ getInt()};
	int y{ getInt() };

	cout << "The largest value is: " << ((x > y) ? x : y) << endl;

	return 0;
}





