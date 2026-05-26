#include<iostream>
using namespace std;


int main(){


int a, b, temp;

cout<<"Enter two numbers"<<endl;

cin>>a>>b;

cout<<"Before Swapping: "<<endl;
cout<<"a = "<<a<<endl;
cout<<"b = "<<b<<endl;

a = a^b;
cout<<a<<endl;
b = a^b;
cout<<b<<endl;
a = a^b;
cout<<a<<endl;

cout<<"After Swapping: "<<endl;
cout<<"a = "<<a<<endl;
cout<<"b = "<<b<<endl;

return 0;
}
