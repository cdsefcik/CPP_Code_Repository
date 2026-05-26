#include<iostream>
using namespace std;

int main(){

char String[500];
cout<<"Enter the string to reverse: "<<endl;
cin.getline(String,500 );

for(int i = length(String), i >= 0, i-- ){
    cout<<String[i];
}

return 0;
}
