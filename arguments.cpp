



#include <iostream>
using namespace std;

float fToc(float degreesF = 32.0);

int main(){

float Fahrenheit, centigrade;

cout << "Enter a value for Fahrenheit: \t";
cin >> Fahrenheit;

centigrade = fToc(Fahrenheit);

cout << Fahrenheit << "F is "<< centigrade << "C";
cout << endl << "Freezing poin: "<< fToc() << "C";

    return 0;
}


float fToc(float degreesF){

    float degreesC = ((5.0/9.0) * (degreesF - 32.0));
    return degreesC;
}
