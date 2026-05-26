
#include <iostream>
#include <string>
using namespace std;


int reverse(int x);

int main(){

cout <<reverse(1534236469);


    return 0;
}


    int reverse(int x) {
        
    string intconvert = to_string(x);
    string converted;
    
        
    if(intconvert.at(0) == '-'){
    converted += '-';
    intconvert.erase(0,1);    
    }
        
    while(intconvert.length() > 0){
    converted += intconvert.at(intconvert.length()-1);    
    intconvert.erase(intconvert.length()-1,intconvert.length());    
    }
        
     
    try{ 
    return stoi(converted);
    }
    catch(...){
        return 0;
    }   
        
    }
