//------------------------------------
//      Subtract the Product and Sum of Digits of an Integer.
//      Ex: INPUT: n = 234
//          OUTPUT: 15
//          Product of digits = 2 * 3 * 4 = 24
//          Sum of digits = 2 + 3 + 4 = 9
//          Result= 24 - 9 = 15
//------------------------------------

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter an integer: ";
    cin>>n;

    int prod = 1;
    int sum = 0;
    while(n!=0){
        int digit = n%10;
        prod*=digit;
        sum+=digit;
        n=n/10;
    }
    cout<<"Product of digits: "<<prod<<endl;
    cout<<"Sum of digits: "<<sum<<endl;
}