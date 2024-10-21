#include<iostream>
#include<string>

using namespace std;

/*
*Example of static member variables.
* Static members are shared by all the members of the class. Allocate memory only once.
*
*/
class Alpha {
private:
	int a;
	int b;
public:
	Alpha() {
		a = 5;
		b = 5;
		stat++;
	}

	static int stat;

};

int Alpha::stat = 0;


//To create the static member, create it outside the class, the data type, class, scope resolution operator, the static member name.

int main() {
	
	Alpha a1;
	Alpha a2;
	Alpha a3;

	cout << "Value using a1 obj = " << a1.stat << endl;
	cout << "Value using a1 obj = " << a2.stat << endl;
	cout << "Value using class name = " << Alpha::stat << endl;

	return EXIT_SUCCESS;
}

