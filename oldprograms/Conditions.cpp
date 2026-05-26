

#include <iostream>
using namespace std;

int main(){

int a,b,max;
a = 1;
b = 2;

cout << "Variable a value is: ";
cout << ((a != 1) ? "not one,": "One");
cout << ((a % 2 != 0) ? "Odd" : "Even");

cout << ((b != 1) ? "1" : "2");

max = (a < b) ? a : b;
cout << max << endl;


    return 0;
}