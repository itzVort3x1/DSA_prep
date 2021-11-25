//------------------------------------
//      Complement of Base 10 Integer
//      Ex: INPUT: n = 5
//          OUTPUT: 2
//          EXPLANATION: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
//------------------------------------

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number you want to find the complement of: ";
    cin>>n;

    int m=n;
    int mask = 0;
    int ans;
    if(m==0){
        ans = 1;
    }
    while(m!=0){
        mask = (mask<<1) | 1;
        m=m>>1;
    }
    ans = (~n) & mask;
    cout<<"The complement of the entered Number is: "<<ans<<endl;
}