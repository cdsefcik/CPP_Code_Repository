

#include <string>
#include <iostream>
using namespace std;


int main(){

string name;

cout << "Enter a name: "<< endl;
cin >> name;
cout << "Welcome"<< name << endl;

cout << "Please enter your full name: "<< endl;
cin.ignore(256,'\n');
getline(cin,name);
cout << "Your name is: "<< name<< endl;

    return 0;
}