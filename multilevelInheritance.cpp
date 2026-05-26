#include<iostream>
using namespace std;

class vehicle{
public:
    vehicle(){
    cout<<"This is a vehicle"<<endl;
    }
};

class fourWheeler:public vehicle{

public:
    fourWheeler(){
    cout<<"Objects with 4 wheeler vehicles"<<endl;
    }

};

class car:public fourWheeler{

public:
car(){
cout<<"Car has four wheels "<<endl;
}

};

int main(){

car obj;
return 0;

}


