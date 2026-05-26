class StudentIL {
public:

	int age;
	const int rollNumber;
	int& x;

	StudentIL(int r, int age): rollNumber(r), age(age), x(this->age){ //This is the use of initiazation list. This sets the constant value when the memory is instantiated. Can also be used for normal variables, such as the age variable.
    
	}

};