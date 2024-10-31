#include<iostream>
#include<string>

using namespace std;

/*
*Data type conversions.
* 
*/


int main(){

	int var1;

	//Declare a float variable
	float var2 = 10.5;

	var1 = static_cast<int>(var2 + 43.1234 + 'C'); //SB 120

	cout << "\n the value is: " << var1;
	cout << "\n the value is: " << var2;
	
	return EXIT_SUCCESS;
}

