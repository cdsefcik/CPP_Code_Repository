

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


Dog(int,int,string);
~Dog();

int getAge() {return age;}
int getWeight() {return weight;}
string getColor() {return color;}

};


Dog::Dog(int age, int weight, string color){
this -> age = age;
this -> weight = weight;
this -> color = color;
}

Dog::~Dog(){
    cout<< "Object destroyed. "<< endl;
}

int main(){
Dog fido(3,15,"brown");
Dog pooch(4,18,"gray");

cout << " Pooch is a "<< pooch.getAge() <<" dog "<< endl;
cout << " Fido is " << pooch.getColor()<< "Years old " << endl;
cout << " Fido is " << pooch.getWeight()<< "Pounds" << endl;
pooch.bark();
    return 0;
}