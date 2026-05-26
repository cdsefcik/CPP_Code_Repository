#include<iostream>
using namespace std;

/*
class Hello_world{
public:
    Hello_world(){
    cout<<"Constructor is called"<<endl;
    }

    ~Hello_world(){
    cout<<"Destructor is called"<<endl;
    }

    void display(){
    cout<<"Hello world!"<<endl;
    }

};

int main(){
Hello_world obj;
obj.display();

}
*/

class students{

public:
    int roll_no;

    ~students(){
    cout<<"Destructor is called for roll number"<<roll_no<<endl;
    }

};

int main(){
students obj1;
obj1.roll_no = 4;
int i = 0;
while(i<5){
    students obj2;
    obj2.roll_no = i;
    i++;
}

return 0;
}
