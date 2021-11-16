#include<iostream>
using namespace std;

int main() {
    // integer
    int a = 5;
    cout << a << endl;

    char b = 'v';
    cout << b << endl;

    // true=1 false=0
    bool bl = true;
    cout << bl << endl;

    float f = 1.2;
    cout << f << endl;

    double d = 1.23;
    cout << d << endl;

    // type casting from char to int.... This prints the ascii value
    int z = 'a';
    cout << z << endl;

    char y = 98;
    cout << y << endl;

    cout << "Size of a is : " << sizeof(a) << endl;
    cout << "Size of f is : " << sizeof(f) << endl;
    cout << "Size of d is : " << sizeof(d) << endl;

    unsigned int u = -112;
    cout << u << endl;

    //operators
    // + - * / %
    cout << 2.0/5.0 << endl;
    // relational operators
    // == != < > <= >=
    cout << (2==8) << endl;
    cout << (2!=3) << endl;
    // here for the comparision ascii value is considered
    cout << (a<b) << endl;

    // logical operators
    // && || !
    cout << (a<b && b>a) << endl;
}