#include<iostream>
using namespace std;

int main(){
int n;

cout <<"Enter the size of the array: " << endl;
cin>> n;

int a[n];
int areverse[n];

cout<<"Enter the integers for the original array: " << endl;
for(int i = 0; i < n; i++){
cin>>a[i];
}

//Reverse the array
int j = 0;
for(int i = (n-1); i >= 0; i--){
areverse[j] = a[i];
j++;
}

//Print reversed array
for(int i = 0; i < n; i++){
    cout<<areverse[i]<<" ";
}

return 0;
}
