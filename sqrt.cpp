

#include <iostream>
using namespace std;

int sqrroot(int value){

int times = value; 
int result = 0;

while (times > 0){

result += value;
    --times;
}

    return result;
}


int main(){

int value; 
cout << "Enter a integer: " << endl;
cin >> value;

cout << "The square of: "<< value << " Is equal to: " << sqrroot(value);



  return 0;

}



