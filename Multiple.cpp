

#include<iostream>
#include<string>
using namespace std;

class Dog{

int age, weight;
string color;

public:
void bark(){
    cout<< "WOOF!"<< endl;
}

void setValues(int, int, string);

int getAge() {return age;}
int getWeight() {return weight;}
string getColor() {return color;}

};


void Dog::setValues(int age, int weight, string color){
this -> age = age;
this -> weight = weight;
this -> color = color;
}

int main(){
Dog fido;
Dog pooch;

fido.setValues(3,15,"brown");
pooch.setValues(4,18,"Gray");

cout << " Pooch is a "<< pooch.getAge() <<" dog "<< endl;
cout << " Fido is " << pooch.getColor()<< "Years old " << endl;
cout << " Fido is " << pooch.getWeight()<< "Pounds" << endl;
pooch.bark();
    return 0;
}