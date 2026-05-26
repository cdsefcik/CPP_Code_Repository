

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

void setAge(int yrs){
    age = yrs;
}

void setWeight(int lbs) {
    weight = lbs;
}

void setColor (string hue){
    color = hue;
}

int getAge() {return age;}
int getWeight() {return weight;}
string getColor() {return color;}

};

int main(){
Dog fido;
fido.setAge(3);
fido.setWeight(15);
fido.setColor("Brown");

cout << "Fido is a "<< fido.getColor() <<" dog "<< endl;
cout << " Fido is " << fido.getAge()<< "Years old " << endl;
cout << " Fido is " << fido.getWeight()<< "Pounds" << endl;
fido.bark();
    return 0;
}