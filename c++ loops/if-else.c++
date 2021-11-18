#include<iostream>
using namespace std;

int main() {
    // cin for input and cout for output
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n % 2 == 0) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }

    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    if (a > b) {
        cout << "a is greater than b" << endl;
    } else if (a < b) {
        cout << "b is greater than a" << endl;
    } else {
        cout << "a and b are equal" << endl;
    }

    int x = 2;
    int y = x+1;
    if((x=3) == y){
        cout<<x;
    }else {
        cout<<x+1;
    }

    int st = 24;
    if(st > 20){
        cout<<"love";
    }else if(st == 24){
        cout<<"hate";
    }else {
        cout<<"babbar";
    }
    cout<<st;
}