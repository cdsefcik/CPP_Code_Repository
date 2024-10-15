#include<iostream>
#include<string>

using namespace std;

/*
*Structures in C++.
* 
*/


//Used as a nested structure.
struct camera {
	int front;
	int rear;
};

//Definition of structure.
struct person {
	//structure members:
	string name;
	int age;
	float weight;
	float height;
	double salary;
};

struct phone {
	string Name;
	int RAM;
	int ROM;
	string processor;
	camera camera; //Example of a nested structure.
	double price;
};


//Example of how to store multuple students using structure.
struct student {
	int roll_no;
	string name;
	int percentage;

};

//Example of structure padding. This will be a 24 byte struct due to padding. For a 64 bit operating system.
struct padding {
	int age;            //4 bytes
	double salary;      //8 bytes
	short int ID;       //2 bytes
};

int main() {

	//Creat pVar
	person pVar;

	//Set variables
	pVar.name = "Caroline";
	pVar.age = 34;
	pVar.weight = 67.f;
	pVar.height = 5.6f;
	pVar.salary = 80000.78;

	//access data
	pVar.salary = 90000.34;

	//Print data
	cout << endl << "Salary: " << pVar.salary << "\n";


	//PHONE EXAMPLE
	phone moto;

	moto.Name = "moto123";
	moto.processor = "Snapdragon";
	moto.price = 4500;
	moto.camera.front = 13;
	moto.RAM = 4;
	moto.ROM = 32;


	cout << "Name " << moto.Name << endl;
	cout << "Processor " << moto.processor << endl;
	cout << "Camera " << moto.camera.front << endl; //Print our nested strucrure

	//Example of using an array of structure.
	struct student stud[3]; //Array can store data for three studets.

	//Use a loop to store the data for each student.
	for (int i = 0; i < 3; i++) {
		cout << "Student " << i + 1 << endl;
		cout << "Enter roll no " << endl;
		cin >> stud[i].roll_no;
		cout << "Enter name " << endl;
		cin >> stud[i].name;
		cout << "Enter percentage " << endl;
		cin >> stud[i].percentage;
	}

	//Can define and initialize a structure like this:
	student stan = { 23423, "Stan", 90 };

	padding example;

	cout << sizeof(example);
	
	return EXIT_SUCCESS;
}

