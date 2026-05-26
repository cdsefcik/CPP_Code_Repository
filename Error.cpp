

#include <iostream>
using namespace std;


void error(string s){

throw runtime_error (s);

}

int area(int len, int wid){

if (len < 0 || wid < 0) error("Can not enter negative numbers");

return len * wid;
    
}



int main(){

int value1;
int value2;

cout << "Enter two integers";
cin >> value1;
cin >> value2;

cout << "The ares is: " << area(value1, value2);


    return 0;
}