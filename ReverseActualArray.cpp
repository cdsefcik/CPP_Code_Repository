#include<iostream>
#include <limits>
using namespace std;


int main(){

int number;


cout<<"Enter the number of elements in the array: "<<endl;
cin>> number;

int elements[number];

cout<<"Enter the elements in the array: "<<endl;
for(int i = 0; i < number; i++){
    cin>>elements[i];
}

int start = 0;
int end = number-1;

while(start < end){
    int temp = elements[start];
    elements[start] = elements[end];
    elements[end] = temp;

    start++;
    end--;
}

cout<<"After the reverse: "<<endl;
for(int i = 0; i < number;i++){
    cout<<elements[i]<<endl;
}

std::cin.clear(); // reset any error flags
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find a newline
std::cin.get(); // get one more char from the user (waits for user to press enter)
return 0;
}
