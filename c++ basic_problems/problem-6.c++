//------------------------------------
//      Power of Two
//      Ex: INPUT: n = 16
//          OUTPUT: true
//          EXPLANATION: 2^4 = 16
//
//          INPUT: n = 3
//          OUTPUT: false
//          EXPLANATION: 3 does not come in power of 2.
//------------------------------------

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number to find the power of: ";
    cin>>n;

    int flag = 0;
    int val = 0;

    for(int i=0; i<=30; i++){
        int ans = pow(2,i);
        if(ans == n){
            val = i;
            flag = 1;
            break;
        }
    }
    if(flag){
        cout<<"This is the value of 2^"<<val<<" = "<<n;
    }else {
        cout<<"This is not a power of 2";
    }
}