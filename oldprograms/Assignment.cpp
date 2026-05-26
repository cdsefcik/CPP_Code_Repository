

#include <iostream>
using namespace std;


int main() {

int a, b;

cout << "Assign values: ";
cout << "a = " << (a = 8) << "  ";
cout << "b = " << (b = 4);


cout << endl << "Add & assign: ";
cout << (a += b)<< endl;
cout << (a-b)<< endl;
cout << (a*b)<< endl;
cout << (a/=b)<< endl;
cout << (a%=b)<< endl;

    return 0;
}