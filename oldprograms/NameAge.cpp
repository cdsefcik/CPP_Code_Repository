//these header files are equivalent to std_lib_facilities.h 
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std; 


int main(){

cout <<"Please enter your first and age\n";
string first_name;
double age;
cin >> first_name;
cin >> age;
cout<< "Hello," <<first_name<< "(age"<<(age * 12)<<")\n";

    return 0;
}