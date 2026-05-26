#include<iostream>
#include <limits.h>
#include <limits>
using namespace std;


int main(){

int n;
cout<<"Enter the number of elements: "<<endl;
cin>>n;

int largest = INT_MIN;
int smallest = INT_MAX;
int listNumbers[n];

cout<<"Enter the elements: "<<endl;
for(int i = 0; i < n; i++){
 cin>>listNumbers[i];
}

for(int i = 0; i < n; i++){
    if(listNumbers[i] > largest){
        largest = listNumbers[i];
    }
    if(listNumbers[i] < smallest){
        smallest = listNumbers[i];
    }

}

cout<<"The largest number is: " <<largest<<endl;
cout<<"The Smallest number is: " <<smallest<<endl;

std::cin.clear(); // reset any error flags
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find a newline
std::cin.get(); // get one more char from the user (waits for user to press enter)

return 0;
}
