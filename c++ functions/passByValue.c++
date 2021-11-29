#include<iostream>
using namespace std;

void dummy(int n){
    cout<<"n is "<< n+1 << endl;

    //here we make a copy of the entered input.
}

int main() {
    int n;
    cin>>n;

    dummy(n);

    // since a copy is passed onto the function any operation done on that passed value does not affect the input value
    // this is called pass by value. 
    cout<<"Number n is "<< n << endl;

    return 0;

}