#include<iostream>
#include<string>

using namespace std;

/*
*The use of inheritance in c++
*Example of how inherited.
* There are different types of inheritance: Single, Multilevel, Hierarchical, Multiple, Multipath (Diamond, can be solved with the virtual keyword).
*/

class rectangle {
public:
	int length;
	int breadth;

	rectangle() {
		cout << "Default of rectangle class"<<"\n";
	}

	rectangle(int b_arg) {
		cout << "Para of base class"<<"\n";
	}

	void area() {
		cout << "Area Of Rectangle " << length * breadth << "\n";
	}

	void Msg() {
		cout << "It is the base class " << endl;
	}
};

//This class extends rectangle
class cuboid : public rectangle {
public:
	int height;

	//non parameterized derived class constructor that extends the base class.
	cuboid() : rectangle() {
		cout << "Default of derived class" << "\n";
	}

	cuboid(int d_arg) : rectangle(d_arg) {
		cout << "Para of derived class" << "\n";
	}

	void volume() {
		cout << "Volume of cuboid " << length * breadth * height << "\n";
	}

	void Msg() {
		rectangle::Msg(); //This overrides to the base class.
		//cout << "It is the base class " << endl;
	}

};


int main() {
	cuboid c;

	c.length = 10; c.breadth = 20; c.height = 30;

	c.area();
	c.volume();
	c.Msg();

	return EXIT_SUCCESS;
}
