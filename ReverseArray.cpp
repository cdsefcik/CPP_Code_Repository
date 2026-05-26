#include<iostream>
#include <limits>
using namespace std;

int main(){

cout<<"Enter the length of the array:"<<endl;

int length;

cin>> length;
int list[length];
cout<<"Enter the list of integers: "<<endl;
for(int i = 0; i < length; i++){
    cin>>list[i];
}

cout<<"Here is the list reversed: "<<endl;
for(int i = length - 1; i >= 0; i--){
cout<<list[i];
}

std::cin.clear(); // reset any error flags
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find a newline
std::cin.get(); // get one more char from the user (waits for user to press enter)
return 0;
}
