//------------------------------------
//      Setting a bit, clearing and toggling
//------------------------------------

#include<iostream>
using namespace std;

int main(){
    int n = 15, k = 0;

    // setting a bit
    cout << (n | (1 << k)) << endl;

    // clearing a bit
    cout << (n & ~(1 << k)) << endl;

    // toggling a bit
    cout << (n ^ (1 << k)) << endl;

    return 0;
}
