#include<iostream>
#include<string>

using namespace std;

/*
*OOP Example.
* 
*/

//Class
class house {

    private:
	//Member variables
	int length = 0, breadth = 0;

	public:
	//Constructor
    
	//Member functions
	void setData(int x, int y) {
		length = x;
		breadth = y;
	}

	void area()
	{
		cout << "Area of house: " << length * breadth<<"\n";
	}
};


int main(){

	house h1, h2;

	//object 1
	h1.setData(5,6);
    h1.area();

	//object 2
	h2.setData(7, 1);
	h2.area();
	
	return EXIT_SUCCESS;
}

