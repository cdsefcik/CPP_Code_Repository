#include<iostream>
#include<string>

using namespace std;

const int MAX = 5;

/*
*Pointers in c++
*Memory Management in c++
*/

void Square(int* ptr);
void printArray(int* ptr);

class person {

private:
	int age;
	string name;
public:
	person(int age, string name) {
		this->age = age;
		this->name = name;
	}

	//Destructor
	~person() {
		cout << "This is the destructor" << endl;
	}

	void printValue() {
		cout << "Age " << age << endl;
		cout << "Name " << name << endl;
	}
};

class Test {
private:
	int data;

public:
	void setData(int set) {
		data = set;
	}

	int getData() {
		return data;
	}
};

int main() {

	int number2 = 10; //create variable.
	int* ptr2 = NULL; //Create pointer initialize it with NULL.
	ptr2 = &number2; //assign the number address to the pointer.

	cout << "PTR: " << ptr2 << endl;
	cout << "*PTR: " << *ptr2 << endl;

	//Looping through an array with a pointer.
	int arr[5] = {10,20,30,40,50};
	int *ptr = arr;
	for (int i = 0; i < 5; i++) {
		cout << *(ptr + i) << endl;
	}

	//Three ways to pass arguments to functions: Value, pointer, reference.
	int number = 10;

	cout << "Before " << number << endl;

	Square(&number);

	cout << "After " << number << endl;

	//Passing an array
	int number3[MAX] = {10,20,30,40,50 };
	printArray(number3); //Can use &number[0] also.
	cout << "\n";

	//Memory Management, uses new and delete, unlike C which uses malloc etc.
	//Create the array with pointer
	int* ptr10 = new int[5];

	//Assign first value
	*ptr10 = 10;

	//Assign next value
	*(ptr10 + 1) = 20;

	//Create an object to the Test class
	Test *ptr3 = new Test;

	//Pointer
	ptr3->setData(10);

	cout << "Value is " << ptr3->getData()<<endl;

	//The programmer must deallocate the memory.
	//Exe
	delete[] ptr3;

	//Using the this keyword.
	person a(45, "Jon");
	a.printValue();

	return EXIT_SUCCESS;
}

void Square(int* ptr) {
	int tmp = *ptr;
	tmp = tmp * tmp;
	*ptr = tmp;
}

void printArray(int* ptr) {
	for (int i = 0; i < MAX; i++) {
		cout << *ptr++;
	}

}
