#include <string>
#include <iostream>
using namespace std;

class Man{

public:
void speak() {cout << "Hello!" << endl;}
void speak(string msg) {cout << " " << msg << endl;}


};

class Hombre : public Man{

public:
void speak(string msg) {cout << msg << endl;}

};

int main(){

Man henry;
Hombre enrique;

henry.speak();
henry.speak("Its a beautiful evening. ");

enrique.speak("Hola!");
enrique.Man::speak("Es Una tarde hermosa. ");

return 0;

}
