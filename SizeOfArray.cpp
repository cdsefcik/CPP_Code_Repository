#include<iostream>

using namespace std;

/*
*Calculates the length of an array using the sizeof() function
*/


int main() {
	
	int array1[10] = { 0 };

	int arraySize = (sizeof(array1) / sizeof(array1[0]));

	cout << "The size of the array is: " << arraySize << endl;
	

	return EXIT_SUCCESS;
}
