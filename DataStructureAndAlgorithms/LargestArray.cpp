#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

int main(){
int n;
int largestNumber = INT_MIN;
int SmallestNumber = INT_MAX;

cout<<"Enter the size of the array: "<< endl;
cin>> n;
cout<<"Enter the numbers: "<< endl;

int numbers[n];

for(int i = 0; i < n; i++){
cin>>numbers[i];
}

for(int i = 0; i < n; i++){
if(numbers[i] > largestNumber){
    largestNumber = numbers[i];
  }
if(numbers[i] < SmallestNumber){
    SmallestNumber = numbers[i];
}
}

cout<<"The largest number is: "<<largestNumber<<endl;
cout<<"The smallest number is: "<<SmallestNumber<<endl;

return 0;
}
