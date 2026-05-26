#include <iostream>
using namespace std;


int main(){
int a;
int b;
int temp;

cout << "Enter two numbers for variable a and variable b: "<< endl;
cin>> a;
cin>> b;

//Swap numbers
//temp = a;
//a = b;
//b = temp;
//a = a^b;
//b = a^b;
//a = a^b;
swap(a,b);

cout<<"The number a is: "<< a<<" The number b is: "<< b<< endl;

return 0;
}
