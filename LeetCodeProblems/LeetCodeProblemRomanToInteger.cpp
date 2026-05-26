
   
#include<iostream>
#include<string>
using namespace std;

 int romanToInt(string s);


int main(){

string example = "IVVV";
cout<<romanToInt(example);

    return 5;
}
   
   
   
   
    int romanToInt(string s) {
        
    int counter = 0;
    int finalnumber = 0;
       
       
        while(counter < s.length()){
            
            //Code for I before V  not last character
            if((s.at(counter) == 'I') and (counter != s.length() -1) and (s.at(counter+1) == 'V')){
            finalnumber += 4;
            counter += 2;
            continue;
                
            }
            //Code for I before X  not last character
            if((s.at(counter) == 'I') and (counter != s.length() -1) and (s.at(counter+1) == 'X')){
            finalnumber += 9;
            counter += 2;
            continue;
                
            }
            //Code for X before L  not last character
            if((s.at(counter) == 'X') and (counter != s.length() -1) and (s.at(counter+1) == 'L')){
            finalnumber += 40;
            counter += 2;
            continue;
                
            }
            //Code for X before C  not last character 
            if((s.at(counter) == 'X') and (counter != s.length() -1) and (s.at(counter+1) == 'C')){
            finalnumber += 90;
            counter += 2;
            continue;
                
            }
            //Code for C before D  not last character
            if((s.at(counter) == 'C') and (counter != s.length() -1) and (s.at(counter+1) == 'D')){
            finalnumber += 400;
            counter += 2;
            continue;
                
            }
            //Code for C before M  not last character
            if((s.at(counter) == 'C') and (counter != s.length() -1) and (s.at(counter+1) == 'M')){
            finalnumber += 900;
            counter += 2;
            continue;
                
            }
            //Code for I and not before I or V
            if((s.at(counter) == 'I')){
            finalnumber += 1;
            counter += 1;
            continue;
                
            }
            //Code for V
            if((s.at(counter) == 'V')){
            finalnumber += 5;
            counter += 1;
            continue;
                
            }
            //Code for X and not before L or C
            if((s.at(counter) == 'X')){
            finalnumber += 10;
            counter += 1;
            continue;
                
            }
            //Code for L
            if((s.at(counter) == 'L')){
            finalnumber += 50;
            counter += 1;
            continue;
                
            }
            //Code for C and not before D or M
            if((s.at(counter) == 'C')){
            finalnumber += 100;
            counter += 1;
            continue;
                
            }
            //Code for D
            if((s.at(counter) == 'D')){
            finalnumber += 500;
            counter += 1;
            continue;
                
            }
            //Code for M
            if((s.at(counter) == 'M')){
            finalnumber += 1000;
            counter += 1;
            continue;
                
            }
            
            
            counter++;
        }   
        
    return finalnumber;      
    }

