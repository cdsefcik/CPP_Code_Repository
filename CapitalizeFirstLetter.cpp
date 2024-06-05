#include<iostream>
#include<string.h>
using namespace std;


int main(){

string sentence;
string sentence2;
cout<<"Enter the sentence: "<<endl;
getline(cin,sentence);
int pre;
for(int i = 0; i < sentence.length(); i++){
        if(i == 0){
            sentence2 += toupper(sentence[i]);
            pre = 1;
        }

        else if((sentence[i] == ' ')){
            sentence2 += ' ';
            pre = 0;
        }

        else if((i != 0) && (pre == 1) && (sentence[i] != ' ')){     //
            sentence2 += tolower(sentence[i]);
            pre = 1;
        }
        else if((i != 0) && (pre == 0) && (sentence[i] != ' ')){     //
            sentence2 += toupper(sentence[i]);
            pre = 1;
        }

}

cout<<sentence2<<endl;
return 0;

}
