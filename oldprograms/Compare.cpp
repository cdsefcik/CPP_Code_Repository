

#include <iostream>
using namespace std;

int main(){

int nil = 0, num = 0, max = 1; char cap = 'A', low = 'a';

cout << "Equality comparisons:";
cout << "1:"<< (nil == num)<< "(true)";
cout << "2:"<< (cap == low) << "(False)";

cout << endl <<"Inequality comparisons:";
cout << (nil != max);
cout << (nil > max);
cout << (nil <max);
cout << (nil >= num);
cout << (max <= num);


    return 0;
}