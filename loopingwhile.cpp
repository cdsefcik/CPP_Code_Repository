
#include <vector>
#include <iostream>
using namespace std;


int main(){

vector<int> vec(10);
int i = 0;

do {

    i++;
    if (i == 3){cout << "This is three";continue;}
    if (i == 8){cout << "The number is: " << i; break;}
    vec[i-1] = i;
    cout <<" | " << vec.at(i-1);
}while (i < vec.size());


    return 0;
}