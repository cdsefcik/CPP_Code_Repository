#include<iostream>
#include<string>

using namespace std;

/*
* Use of templates. Templates help with being able to create one function for multiple data types.
*/



//Example of a template function
template <class T>
T sum(T x, T y) { //Template Function

	return x + y;
}

//Define a generic class
template<class T>
class add {

private:
	T x;
	T y;

public:
	add(T arg1, T arg2) {
		x = arg1;
		y = arg2;
	}
	void getSum() {
		cout << x + y << endl;
	}
};

int main() {

	cout << sum<int>(3, 7) << endl;
	cout << sum<double>(3.0, 7.0) << endl;
	cout << sum<float>(3.4f, 9.5f) << endl;
	cout << sum<string>("Vedinesh", "Academy") << endl;

	add<int> obj1(2, 3);
	add<int> obj2(2.0f, 3.0f);

	obj1.getSum();
	obj2.getSum();

	return EXIT_SUCCESS;
}
