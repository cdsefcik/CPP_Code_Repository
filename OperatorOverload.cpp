#include<iostream>
#include<string>

using namespace std;

/*
*Operator overloading. When operators(+,-, /, *) work for user-defined types like objects and structures. The is done by the programmer.
*
* 
*/

class A {

private:
	int weight;
public:
	A(int x = 0) {
		weight = x;
	}

	void PrintValue() {
		cout << "Weight is " << weight<<"\n";
	}

	//Overloaded + operator.
	A operator+(A w) {
		A temp;
		temp.weight = weight + w.weight;
		return temp;
	}

    //Overloaded ++ operator.
	void operator++() {
		++weight;
	}

	void operator++(int) {
		weight++;
	}

	//Overloaded -- operator.
	void operator--() {
		--weight;
	}

	void operator--(int) {
		weight--;
	}
};


int main() {
	int a = 34, b = 45, c = 0;

	cout << endl << "Total " << c<<"\n";

	//Operator overloading
	A person1(89);
	A person2(99);
	A total;

	total = person1 + person2;
	total.PrintValue();

	++total;

	total.PrintValue();

	total++;

	total.PrintValue();

	total--;

	total.PrintValue();

	return EXIT_SUCCESS;
}
