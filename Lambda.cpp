#include<iostream>
#include<string>

using namespace std;

/*
*Use of Lambdas.
*Lambda is an anonymous function.
*Quick function in a simple line(declared on the fly)
* No extra time to jump in/out - function definition.
*/



int main()
{
	//Lambda by value
	string msg = "ByteBoard - ";
	

	auto sum = [msg](string a, string b) -> string {return msg + a + " " + b; };

	cout << sum("Vediniesh", "Academy") << endl;

	//Lambda by reference
	int arr[5] = { 1,2,3,4,5 };

	auto sum1 = [&arr]() -> int {

		int total = 0;
		for (int i = 0; i < 5; i++) {
			total += arr[i];
		}
		return total;
		};

	cout << sum1() << endl;
}


