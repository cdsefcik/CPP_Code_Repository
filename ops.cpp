#include "ops.h"
#include <iostream>
using namespace std;

Calculator::Calculator()
{status = true;}

void Calculator::launch(){

    cout << endl << "*** SUM CALCULATOR***" << endl;
    cout << "Enter the operator" << endl << "Hit the return " << endl;
}

void Calculator::readinput(){

    cout << ">"; cin >> num1;
    if (num1 == 0)status = false;
    else {cin >> oper; cin >> num2;}
}

void Calculator:: writeOutput()
{

if(status) switch(oper)
{

case '+': {cout << (num1 + num2) << endl; break;}
case '-': {cout << (num1 - num2) << endl; break;}
case '*': {cout << (num1 * num2) << endl; break;}
case '/': if (num2 != 0)
    cout << (num1 / num2) << endl;
    else cout << "Cannot divide by zero" << endl;

  }

}

bool Calculator::run() {return status;}