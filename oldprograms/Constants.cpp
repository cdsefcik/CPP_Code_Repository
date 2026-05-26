#include <iostream>
using namespace std;


int main(){

const double PI = 3.1415926536;
cout << "6\" Circle Circumference:" << (PI *6) << endl;

enum
{RED=1,YELLOW,GREEN,BROWN,BLUE,PINK,BLACK};
cout << "1: " << RED <<endl;
cout << "2: " << BLUE << endl;
cout << "3: " << (RED + BLUE) << endl;

typedef enum{NEGATIVE, POSITIVE} charge;
charge neutral = NEGATIVE, live = POSITIVE;
cout << "4: " << neutral << endl;
cout << "5: " << live << endl;


    return 0;
}