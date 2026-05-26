#include<iostream>
using namespace std;


int main(){

char name[100];

cout<<"Enter your name: ";

cin>>name;
name[3] = '\0';
name[4] = 'x';

cout<<"Your name is "<<name<<endl;

return 0;
}
