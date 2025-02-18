#include<iostream>

using namespace std;

/*
* Geometric Sum
* Provides an example of programming with recursion. 
*/

double gSum(int k) {
	//base case
	if (k == 0) {
		return 1;
	}

	//recursive case
	double smallAns = gSum(k-1);

	//calculation
	return smallAns + 1.0 / pow(2, k);
    
}


int main() {

	    int a;
		cout << "Enter the number: ";
		cin >> a;
		
		cout << gSum(a);

		return 0;

}
