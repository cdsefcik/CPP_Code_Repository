#include<iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int numberator, int denominator) {
        this->numerator = numberator;
        this->denominator = denominator;
    }

    Fraction() {

    }

    //Note, should make functions constant when they qualify as constant. That is, when they do not make any changes to the data.
    int getNumerator() const{
        return numerator;
    }

    int getDenominator() const{
        return denominator;
    }

    void setNumerator(int n) {
        numerator = n;
    }

    void setDenominator(int d) {
        denominator = d;
    }


    void print() const{
        cout << this->numerator << "/" << denominator << endl;
    }

    Fraction add(Fraction const& f2) const {
        int lcm = this->denominator * f2.denominator; ///optional
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * numerator + y * f2.numerator;

        //store the result in f1
        //this->numerator = num;
        //this->denominator = lcm;

        Fraction fnew(num, lcm);

        fnew.simplify();
        
        return fnew;
    }

    Fraction operator+(Fraction const& f2)const {
        int lcm = this->denominator * f2.denominator; ///optional
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * numerator + y * f2.numerator;

        //store the result in f1
        //this->numerator = num;
        //this->denominator = lcm;

        Fraction fnew(num, lcm);

        fnew.simplify();

        return fnew;
    }

    void multiply(Fraction const &f2) {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;
        simplify();

    }

    Fraction operator*(Fraction const &f2) const {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;
        
        Fraction fnew(n, d);
        fnew.simplify();
        return fnew;
    }

    bool operator==(Fraction const &f2) const {
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    //
    void simplify() {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 1; i <= j; i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                gcd = i;
            }
        }

        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }

    //Pre increment
    Fraction& operator++() {
        numerator = numerator + denominator;
        simplify();

        return *this; //Need to return the content, not the address of the object.
    }

    //Post Increment
    Fraction operator++(int) {
        Fraction fnew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }

    Fraction& operator+=(Fraction const& f2) {
        int lcm = this->denominator * f2.denominator; ///optional
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * numerator + (y * f2.numerator);

        
        numerator = num;
        denominator = lcm;       
        simplify();
        return *this;
    }
};

