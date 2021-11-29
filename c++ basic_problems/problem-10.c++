//------------------------------------
//      Arithmetic progression
//      Ex: INPUT: n = 3
//          OUTPUT: 16
//          EXPLANATION: AP = (3*n + 7)
//                          = (3*3 + 7)
//                          = (9 + 7)
//                          = 16
//------------------------------------

#include<iostream>
using namespace std;

int AP(int n){
    return (3*n + 7);
}

int main(){
    int n;
    cout<<"Enter the nth Term you want to find in AP: ";
    cin>>n;
    int res = AP(n);
    cout<<"The nth term in AP is: "<<res<<endl;
}