

#include <iostream>
using namespace std;

class Token{
public:
    char kind;
    double value;
    Token(char ch)
        :kind(ch), value(0){}
    Token(char ch, double val)
        :kind(ch), value(val){}


};


int main(){


    return 1;
}