#include<iostream>
#include<cstring>
using namespace std;


void printAllprefixes(char str[]){

for(int i = 0; str[i] != '\0'; i++){
    for(int j = 0; j <= i; j++){
        cout<<str[j];
        }
        cout<<endl;
    }
}

int main(){

char str[] = "abcd";
char str2[500];

cout<<"Enter the string: "<<endl;
cin>>str2;

printAllprefixes(str2);

return 0;
}
