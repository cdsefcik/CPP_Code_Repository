#include<iostream>
using namespace std;

int main(){
int n;

cout <<"Enter the size of the array: " << endl;
cin>> n;

int a[n];

cout<<"Enter the integers for the original array: " << endl;
for(int i = 0; i < n; i++){
cin>>a[i];
}

int start = 0;
int end = (n-1);
while(start <= end){
swap(a[start],a[end]);
start++;
end--;
}

cout<<"After reverse: " << endl;
for(int i = 0; i < n; i++){
cout<<a[i]<<" ";
}

return 0;
}
