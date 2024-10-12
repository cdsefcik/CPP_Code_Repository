#include<iostream>

using namespace std;

/*
*Function to add the values in a 2D array.
*/


int main() {
	
	int arr[5][5], sum = 0;

	int arraySize = (sizeof(arr) / sizeof(arr[0]));

	//Input
	for (int i = 0; i < arraySize; i++) {
		for (int j = 0; j < arraySize; j++) {
			cout << endl << "Row is: " << i << " Column is: " << j << " Enter a value: ";
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	}

	//Add values
	cout << endl << "The sum of the values is: " << sum;
	

	return EXIT_SUCCESS;
}
