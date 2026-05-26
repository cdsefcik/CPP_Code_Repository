#include<iostream>
using namespace std;

class ParamA{

int b,c;

public:
    ParamA(int b1, int c1){
    b = b1;
    c = c1;

    }

    int getx(){
    return b;
    }

    int gety(){
    return c;
    }

};


int main(){

ParamA par(15, 16);
cout<<"Value b: "<<par.getx()<<endl;


}
