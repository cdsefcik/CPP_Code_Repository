#include<iostream>
#include<cstring>

using namespace std;
bool mystrcmp(char str1[], char str2[]){
if(strlen(str1) != strlen(str2)) return false;

for(int i = 0;i<strlen(str1);i++){
    if(str1[i] != str2[i]) return false;
}
return true;
}




int main(){

char str1[100] = "abcd";
char str2[100] = "def";

cout<<"Befor copying"<<endl;
cout<<"str1 "<<str1<<endl;
cout<<"str2 "<<str2<<endl;

strcpy(str1, str2);

cout<<"After copying"<<endl;
cout<<"Str1 "<<str1<<endl;
cout<<"str2 "<<str2<<endl;


//cin>>str1>>str2;
//int len = strlen(str1);
//cout<<len<<endl;
//if(mystrcmp(str1,str2)){
/*    cout<<"Equal"<<endl;
}else{
cout<<"Not equal"<<endl;
}
*/
return 0;

}
