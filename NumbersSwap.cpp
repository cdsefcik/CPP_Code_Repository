#include<iostream>
using namespace std;


int main(){

int a, b, temp;

cout<<"Enter two numbers"<<endl;

cin>>a>>b;

cout<<"Before Swapping: "<<endl;
cout<<"a = "<<a<<endl;
cout<<"b = "<<b<<endl;

temp = a;
a = b;
b = temp;

cout<<"After Swapping: "<<endl;
cout<<"a = "<<a<<endl;
cout<<"b = "<<b<<endl;

return 0;

}
