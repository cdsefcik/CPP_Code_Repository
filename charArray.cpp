#include<iostream>
using namespace std;


int length(char input[]){
int counter = 0;

do{
if(input[counter] != '\0')
 counter++;

}while(input[counter] != '\0');

return counter;

}

void reverse(char input[]){

    int start = 0;
    int end = length(input) - 1;

    while(start < end){
        swap(input[start], input[end]);
        start++;
        end--;
    }

}

int main(){

char name[100];

cout<<"Enter the characters: "<<endl;
cin.getline(name, 100);

cout<<"Length of name is: "<<endl;
cout<<length(name)<<endl;

cout<<"reversed character array is: "<<endl;
reverse(name);
cout<<name;

return 0;

}
