

#include <iostream>
using namespace std;

float bodyTempc();
float bodyTempf();


int main(){

cout << "Centigrade:" << bodyTempc() << endl;
cout << "Fahrenheit: "<< bodyTempf() << endl;

    return 0;
}


float bodyTempc(){

float temperature = 37.0;
    return temperature;

}

float bodyTempf(){

float temperature = 98.6;
    return temperature;

}