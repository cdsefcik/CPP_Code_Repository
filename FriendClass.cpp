#include<iostream>
#include<string>

using namespace std;

/*
*Demonstrates friend class.
*Also demonstrates operator overloading between two different instantiations of a class.
*/

class Alpha {
private:
	int a1;
public:
	Alpha(int arg = 0) {
		a1 = arg;
	}
	friend void fun();
	friend class Charlie;

	friend bool operator>(Alpha a, Alpha b);
	friend bool operator<(Alpha a, Alpha b);
};

//Overloaded functions:
bool operator<(Alpha a, Alpha b) {
	return a.a1 < b.a1;
}

bool operator>(Alpha a, Alpha b) {
	return a.a1 > b.a1;
}

class Charlie {
private:
	int c1;
public:
	Charlie(int arg = 0) {
		c1 = arg;
	}
	int Sum() {
		Alpha a(9);

		int sum = a.a1 + c1;

		return sum;
	}

};

class Beta {
private:
	int b1;
public:
	Beta(int arg = 0) {
		b1 = arg;
	}
	friend void fun();
};

void fun() {
	Alpha a(8);
	Beta b(2);

	int x = a.a1 + b.b1;
	cout << "Sum " << x << endl;
}

int main() {
	
	fun();

	Charlie b(2);
	cout << "Sum is: " << b.Sum() << endl;

	//Operator overloading: Can't compare the two, need the overloaded operators in the Alpha class.
	Alpha jon(20);
	Alpha jim(30);

	if (jon > jim) {
		cout << "Jon wins" << endl;
	}
	else if (jon < jim) {
		cout << "Jim wins" << endl;
	}

	return EXIT_SUCCESS;
}

