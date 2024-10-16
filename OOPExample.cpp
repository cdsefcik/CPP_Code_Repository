#include<iostream>
#include<string>

using namespace std;

/*
*OOP Example.
*Use of constructors: Non parameterized.
* 
*/

//Class house
class house {

private:
	//Member variables
	int length = 0, breadth = 0;

public:

	//Member functions
	void setData(int x, int y) {
		length = x;
		breadth = y;
	}

	void area()
	{
		cout << "Area of house: " << length * breadth << "\n";
	}
};


//Class Person, uses a constructor.
class Person {
private:
	string name;
	int age;
	float height;
public:
	
	/*
	Person() { //Non parameterized constructor. This constructor does not work currently as the parameterized constructor is overloaded.
		name = "Null";
		age = 0;
		height = 0.0f;
	}
	*/

	//Parameterized constructor: We can overload the constructor below by assigning values if nothing is provided. This takes the place of the default constructor.
	Person(string name_a = "Null", int age_a = 0, float height_a = 0.0f) {
		name = name_a;
		age = age_a;
		height = height_a;
	}

	//Copy Constructor
	Person(Person& obj2) {
		name = obj2.name;
		age = obj2.age;
		height = obj2.height;
	}

	//Getter function to get the values in the member 
	void getData() {
		cout << "Get name: " << name << '\n';
		cout << "Get age: " << age << '\n';
		cout << "Get height: " << height << '\n';
	}
};


int main() {

	house h1, h2;

	//object 1
	h1.setData(5, 6);
	h1.area();

	//object 2
	h2.setData(7, 1);
	h2.area();

	Person obj;
	obj.getData();

	Person obj2("Chris", 34, 5.10f);
	obj2.getData();

	Person obj3(obj2);
	obj3.getData();

	return EXIT_SUCCESS;
}
