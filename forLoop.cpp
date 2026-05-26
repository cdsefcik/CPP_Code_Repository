#include <iostream>
using namespace std;
/*
void power(double base, int exp = 2){

double ans = 1;
for(int i = 1; i <= exp; i++){
  ans = ans * base;
}

cout<<ans;

}

int main(){

int n;
double m;
char ch;
cout<<"Enter a base value"<<endl;
cin>>m;
cout<<"Do you want to input an exponent value (Y/N)"<<endl;
cin>>ch;

if((ch == 'y') || (ch == 'Y')){
    cout<<"Enter exponent value: "<<endl;
    cin>>n;
    power(m,n);
}
else{
    power(m);
}
return 0;
}
*/
/*
int main(){
   int rows;

   cout<<"Enter number of rows: "<<endl;
   cin>>rows;
   for(int i = 1; i <= rows; ++i){

        for(int j = 1; j <= i; ++j){
        cout<<"*";
        }
    cout<<"\n";
   }
return 0;
}
*/
/*
int main(){
char input, alphabet = 'A';

cout<<"Enter the uppercase letter you want to print in the last row: "<<endl;
cin>>input;

for(int i = 1; i <= (input-'A'+1); i++){

    for(int j = 1; j <= i; j++){
       cout<<alphabet<<" ";
    }
    ++alphabet;

    cout<<endl;
}
return 0;
}
*/
/*
int main(){
int rows, coef = 1;

cout<<"Enter the number of rows: ";
cin>>rows;

for(int i = 0; i < rows; i++){
    for(int space = 1; space <= rows-i; space++)
        cout<<"  ";

    for(int j = 0; j <= i; j++){
        if(j==0||i==0)
            coef = 1;
        else
            coef = coef*(i-j+1)/j;

        cout<<coef<<"  ";
    }
    cout<<endl;
}
return 0;

}
*/
/*
int main(){
int rows, number = 1;
cout<<"Enter number of rows: ";
cin>>rows;

for(int i = 1; i <= rows; i++){
    for(int j = 1; j <= i; ++j){
    cout<<number<<"  ";
    ++number;
    }
    cout<<endl;
  }
  return 0;
}
*/
/*
int main(){
int number, sum = 0;

cout<<"Enter a number: ";
cin>>number;

while(number >=0){
    sum += number;
    cout<<"Enter a number: ";
    cin>>number;
}

cout<<"\n the sum is "<<sum<<endl;
return 0;
}
*/
/*
void pyramid(int n){
int i = 0, j=0,k=0;
while(i<n){
    while(k<=n-i-2){
        cout<<" ";
        k++;
    }
    k=0;
    while(j<2*i-1){
        cout<<"*";
        j++;
    }
    j=0;
    i++;
    cout<<endl;
}
}
int main(){
int n = 5;
pyramid(n);
return 0;
}
*/
/*
int main(){
int i =0,n;
cout<<"How many times do you want the output to get printed: ";
cin>>n;

while(i<n){
    cout<<"Hello World!"<<endl;
    i++;
}
}
*/

int main(){

int num = 0, sum=0;

do{
    sum += num;
    cout<<"Enter the number: ";
    cin>>num;

}
while(num >= 0);
cout<<"\n The sum is "<<sum<<endl;

return 0;
}
