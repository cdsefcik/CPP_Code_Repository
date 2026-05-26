

#include<iostream>
#include<string>
#include <stdexcept>
#include <typeinfo>
#include <fstream>
using namespace std;


int main(){

    string lang = "C++";
    int num = 1000000000;
    cout << "Program continues: " << endl;

    try {
        ifstream reader("Nonsuch.txt");
        if( ! reader) throw logic_error("File not found");
    }
    catch (out_of_range &e) {
        cerr <<"Range Exception: "<< e.what()<< endl;
        cerr <<"Exception Type: "<< typeid(e).name();
        cerr << endl << "Program terminated." << endl;
        return -1;
        
    }
    catch (exception &e){

        cerr << "Exceptions: " << e.what() << endl;
        cerr << "Exceptions Type: "<< typeid(e).name() << endl;
        return -1;
    }

    return 0;
}