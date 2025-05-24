#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

unsigned long long int factorialRecursion(int number) {
    if (number == 1) {
        return 1;
    }
    else {
        return number * factorialRecursion(number - 1);
    }

}


int main() {

    int number;
    cout << "Enter a number: " << endl;
    cin >> number;

    cout << "The number is: " << factorialRecursion(number) << endl;

    return 0;
};










