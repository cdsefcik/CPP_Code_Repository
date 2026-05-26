#include<iostream>
using namespace std;

int main(){

    /*int a[10];
    a[0] = 2;
    a[4] = 5;

    cout <<a[0]<<" " <<a[4] << endl;*/

    int a[10] = {1,2,3,4};
    cout << a[0]<< a[1]<< a[2] <<a[3]<< endl;

    for(int i = 0;i<10;i++){
        cout<<a[i]<<" ";
    }

    int b[10];
    for(int i = 0; i < 10; i++){
        cout << b[i]<<" ";
    }

    int c;
    cout<<sizeof(c)<<endl;
    cout<<sizeof(b)<<endl;

    return 0;

}
