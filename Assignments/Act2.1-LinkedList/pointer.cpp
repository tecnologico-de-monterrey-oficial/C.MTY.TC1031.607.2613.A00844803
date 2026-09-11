#include<iostream>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator)
        : numerator(numerator), denominator(denominator) {}

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    int x=42;
    int*p=&x;
    cout<<x<<endl;
    cout<<&x<<endl;
    cout<<*p<<endl;
    cout<<p<<endl;

    int*q= new int(5);
    cout<<q<<endl;
    cout<<*q<<endl;

    delete q;
    cout<<q<<endl;

    Fraction*f= new Fraction(2,3);
    f->print();

    delete f;

    return 0;
}