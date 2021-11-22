#include<iostream>
using namespace std;

int main() {
    int a = 4;
    int b = 6;

    // bitwise operators
    cout<< " a&b "<< (a&b) << endl;
    cout<< " a|b "<< (a|b) << endl;
    cout<< " ~a "<< ~a << endl;
    cout<< " ~b "<< ~b << endl;
    cout<< " a^b "<< (a^b) << endl;

    // left shift/ right shift
    cout<< (17>>1)<<endl;
    cout<< (17>>2)<<endl;
    cout<< (19<<1)<<endl;
    cout<< (21<<2)<<endl;

    //inc / dec operators
    int i=7;
    cout<< (++i) << endl;
    cout<< (i++) << endl;
    cout<< (i--) << endl;
    cout<< (--i) << endl;
}