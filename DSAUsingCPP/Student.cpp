#include<iostream>
#include<cstring>
#include "StudentInitializationList.cpp"
using namespace std;


class Student {
	int age;
	

public:
	char* name;

	//Created copy construcor: Same name as the constructor
	Student(Student const &s) {
		this->age = s.age;
		//this->name = s.name; // Shallow copy
		//Code for deepcopy
		this -> name = new char(strlen(s.name) + 1);
		strcpy(this->name, s.name);
	}

	Student(int age, char* name) {
		this->age = age;
		//this->name = name; This is a shallow copy, only copies the address of the array.
		//Use this instead, makes a new array, then copies the contents of the array, into the new array. This is a deep copy.
		this->name = new char[strlen(name) + 1]; //Creates new array, plus the null character.
		strcpy(this->name, name); //copies, name into new name.
	}

	void display() {
		cout << name << " " << age << endl;
	}

};

/*
int main() {
	/*
	char name[] = "abcd";

	Student s1(20, name);
	s1.display();

	Student s2(s1);
	s2.name[0] = 'x';

	s1.display();
	s2.display(); //Without copy constructor, this creates a shallow copy. Need to create a copy constructor.

	
	name[3] = 'e';
	Student s2(30, name);
	s2.display();

	s1.display();
	*/
/*
	StudentIL  s1(100, 10);
	s1.age = 10;
	
	return 0;
}
*/
