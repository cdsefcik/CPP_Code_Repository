#include<iostream>
using namespace std;


int main(){

char v[6];

cout<<"Enter 6 characters: "<<endl;
    for(int i = 0; i < 6; i++){
        cin>>v[i];
    }

cout<<"The characters are: "<<v<<endl;

char* p = &v[1];
char x = *p;

cout<<"Here is the test character: "<<p<<endl;
cout<<"Here is the test character: "<<x<<endl;

int* num1 = new int(11);
int* num2 = num1;

*num1 = 22;


cout<<"num1 = " <<*num1<< endl;
cout<<"num2 = " <<*num2<< endl;

}
