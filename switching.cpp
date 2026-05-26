

#include <iostream>
using namespace std;


int main(){

int num = 8;

switch (num) {

    case 1: cout << num << "Monday: "; break;
    case 2: cout << num << "Tuesday:" ; break;
    case 3: cout << num << "Wednesday: "; break;
    case 4: cout << num << "Thursday: "; break;
    case 5: cout << num << "Friday: "; break;
    case 6: cout << num << "Saturday: " ;break;
    default: cout << num << "Weekend: "; break;
}

 return 0;
}