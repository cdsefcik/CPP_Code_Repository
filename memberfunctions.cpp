#include<iostream>
using namespace std;

/*
class student{

public:
    char name[30],clas[10];
    int rol, age;

    void enter(){
    cout<<"Enter student name: "<<endl;
    cin.getline(name,30);
    cout<<"Enter student age: "<<endl;
    cin>>age;
    cout<<"Enter student roll number: "<<endl;
    cin>>rol;
    cout<<"Enter student class: "<<endl;
    cin.getline(clas, 10);
    }

    void display(){
    cout<<"\n Age \t Name \t Roll number \t class";
    cout<<"\n"<<age<<"\t"<<name<<"\t"<<rol<<"\t"<<clas;
    }

};

int main(){

student obj1;
obj1.enter();
obj1.display();
return 0;

}
*/

/*
class DB{

double ft, inch;
public:
    double convert();
    void display();

};

double DB::convert(){

cout<<"Enter the values in feet: ";
cin>>ft;
inch = ft * 12;

}

void DB::display(){

cout <<"The value in inches is: "<<inch;

}

int main(){

DB obj1;
obj1.convert();
obj1.display();
return 0;

}
*/

#include <iostream>
#include <string>
using namespace std;

class students{

public:
    string name;
    int rol_no;

    void printName();

    void printRoll(){
    cout<<"Student roll number is: "<<rol_no;
    }

};

void students::printName(){

    cout<<"Student name is: "<<name;

}

int main(){

students obj1;
obj1.name = "Chris";
obj1.rol_no = 4;

obj1.printName();
cout<<endl;

obj1.printRoll();

return 0;

}
