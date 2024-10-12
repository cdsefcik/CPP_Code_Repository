#include<iostream>

using namespace std;

/*
*Function to find the most occurring element in an array.
*/


int main() {
	
	int arr[] = {12,8,15,6,2,9,1,8,9,8,9,9};
	int arraysize = 0, maxOcc = 0, count = 1, maxcount = 0;

	int arraySize = (sizeof(arr) / sizeof(arr[0]));

	
	for (int i = 0; i < arraySize; i++) {
		for (int j = i + 1; j < arraySize; j++) {
			if (arr[i] == arr[j]) {
				count++;
			}
		}
		if (count > maxcount) {
			maxcount = count;
			maxOcc = arr[i];
		}
		count = 1;
	}
	

	cout << endl<< "The max occuring element: " << maxOcc;
	cout << endl << "The time it is occ is: " << maxcount;
	

	return EXIT_SUCCESS;
}
