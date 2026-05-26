#include <iostream>
using namespace std;

int main(){

int n;
cout<<"How many elements are in the array? " << endl;
cin>>n;

//The array
int numbers[n];

cout<<"Enter the array: "<< endl;
for(int i = 0; i < n; i++){
cin>>numbers[i];
}

for(int i = 0; i < n; i++){

    cout<<numbers[i]<<" ";
}

cout << endl;

for(int i = (n-1); i >=0; i--){
    cout<< numbers[i]<<" ";
}


return 0;
}
