

#include <iostream>
using namespace std;

float computeArea(float);
float computeArea(float,float);



int main(){

    float num, area;

    cout << "Enter dimension in feet: ";
    cin >> num;

    area = computeArea (num);
    cout << "The circle"<< area << endl;

    area = computeArea(num, num);
    cout << "Squar ared" << area << endl;


    return 0;
}


float computeArea(float diameter){
float radius = (diameter / 2);
return (3.141593 * (radius * radius));
}

float computeArea (float width, float height){

    return (width * height);
}