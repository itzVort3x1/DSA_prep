//------------------------------------
//      Reverse Integer
//      Ex: INPUT: n = 123
//          OUTPUT: 321
//------------------------------------

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number you want to reverse: ";
    cin>>n;

    int ans = 0;
    while(n!=0){
        int digit = n%10;
        if((ans > INT_MAX/10) || (ans < INT_MIN/10)){
            ans = 0;
        }
        ans = (ans*10)+digit;
        n = n/10;
    }
    cout<<"The reverse of the number entered is: "<<ans<<endl;
}