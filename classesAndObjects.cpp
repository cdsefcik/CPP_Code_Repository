#include<iostream>
using namespace std;

//keyword
class Phone {//class name
//access specifier can be private public or protected.
//public;
public:
    double cost;
    int slots;

//data members (variables to be used)

//member function()



}; //class ends with braces followed by semicolon

class Room{

public:
    double length, breadth, height;

    double calculateArea(){
    return length * breadth;
    }

    double calculateVolume(){
    return length * breadth * height;
    }

};

int main(){

    Phone obj1, obj2;

    //use the object name followed by period follow by the method.
    obj1.cost = 1000.0;
    obj1.slots = 1;

    obj2.cost = 1100.0;
    obj2.slots = 1;

    cout<<"Cost of Iphone 12 is: "<<obj1.cost<<endl;
    cout<<"Cost of Iphone 12 pro max is: "<<obj2.cost<<endl;

    cout<<"Slots of Iphone 12 is: "<<obj1.slots<<endl;
    cout<<"Slots of Iphone 12 pro max is: "<<obj2.slots<<endl;

    Room room1;

    room1.length;
    room1.breadth;
    room1.height;

    cout<<"Please enter length, breadth and height: "<<endl;
    cin>>room1.length>>room1.breadth>>room1.height;

    cout<<"The area is: "<<room1.calculateArea()<<endl;
    cout<<"The area is: "<<room1.calculateVolume()<<endl;



    return 0;

}
