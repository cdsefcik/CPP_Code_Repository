#include<iostream>
#include<cstring>
using namespace std;

//Implement these!
//strlen
//strcmp()
//strcpy()
//strncpy()
//strcat()

void strcopy(char str1[], char str2[]){

for(int i = 0; i <= strlen(str2); i++){
    str1[i] = str2[i];
}

}


int main(){

char str1[500];
char str2[500];

cout<<"Enter string 2: "<<endl;
cin>>str2;

strcopy(str1, str2);

cout<<"Here are the strings: "<<endl;
cout<<str1;
cout<<str2;

}
