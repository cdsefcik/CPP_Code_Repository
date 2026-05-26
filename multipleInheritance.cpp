#include <iostream>
using namespace std;

class vehicle{
public:
    vehicle(){
    cout<<"This is a vehicle"<<endl;
    }
};

class fourWheeler{

public:
    fourWheeler(){
    cout<<"THis is a 4 wheeler vehicle"<<endl;
    }

};

class car:public vehicle, public fourWheeler{


};

int main(){

car obj;
return 0;

}
