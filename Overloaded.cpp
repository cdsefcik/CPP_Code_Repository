

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

void bark(string noise){cout << noise << endl;}


Dog(int,int,string);
~Dog();
Dog();
Dog(int,int);

int getAge() {return age;}
int getWeight() {return weight;}
string getColor() {return color;}

};


Dog::Dog(int age, int weight, string color){
this -> age = age;
this -> weight = weight;
this -> color = color;
}

Dog::Dog(){

    age = 1;
    weight = 2;
    color = "black";
}

Dog::Dog(int age, int weight){
    this -> age = age;
    this -> weight = weight;
    color = "white";
}

Dog::~Dog(){
    cout<< "Object destroyed. "<< endl;
}

int main(){
Dog fido(3,15,"brown");
Dog rex;
Dog pooch(4,18,"gray");

cout << " Pooch is a "<< pooch.getAge() <<" dog "<< endl;
cout << " Fido is " << pooch.getColor()<< "Years old " << endl;
cout << " Fido is " << pooch.getWeight()<< "Pounds" << endl;
cout << "Rex is a  " << rex.getAge();
cout << "Year old " << rex.getColor();
cout << "dog who weights " << rex.getWeight();
cout << "Pounds. ";
rex.bark("GRRR!");
pooch.bark();
Dog sammy(2,6);

cout << "Sammy is a "<< sammy.getAge();
cout << "year old" << sammy.getColor();
cout << "dog who weighs "<< sammy.getWeight();
cout << "Pounds.";
sammy.bark("BOWWOW! ");

    return 0;
}