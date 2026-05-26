class Student {

	//Static properties are those that belong to a class not a single object.
public:
	int rollNumber;
	int age;
	static int totalStudents;

	Student() {
		totalStudents++;
	}
};
