#include<iostream>
#include<string>

using namespace std;

/*
 *Base class pointers from the derived class.
 *Abstract class, which only acts as a base class. Cannot instantiate an object from it.
 *Demonstrates polymorphism. 
*/

class base1 {
public:
	virtual void show() = 0; //This is a true virtual function.

};

class base {
public:
	virtual void show() { //Making it virtual makes it so that the verived class pointers will access the respevtive show() functions.
		cout << "Base Class " << endl;
	}

};

class derv1 : public base //Derived class which extends the base class
{
public:
	void show(){
	  cout << "Derived class 1 " << endl;
	}

};

class derv2 : public derv1 {
public:
	void show() {
		cout << "Derived class 2 " << endl;
	}

};


int main() {
	base* ptr; //pointer of base class.
	ptr = new derv1(); //pointer of base class instantiating memory from the derived class. 
	ptr->show();
	base* ptr2;
	ptr2 = new derv2();
	ptr2 -> show();

	return EXIT_SUCCESS;
}

