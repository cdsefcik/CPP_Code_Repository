#include<iostream>
using namespace std;

class vehicle{
public:
    vehicle(){

    cout<<"This is a vehicle"<<endl;
    }

};

class car:public vehicle{

//we are keeping this class empty

};


int main(){

car obj;
return 0;

}
