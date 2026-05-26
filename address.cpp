

#include<iostream>
#include<string>
using namespace std;


int main(){

int num = 100;
double sum = 0.0123456789;
string text = "C++ is fun";

cout << "Integer variable starts at: " << &num << endl;
cout << "double variable starts at: " << &sum << endl;
cout << "string variable starts at: " << &text << endl;

    return 0;
}