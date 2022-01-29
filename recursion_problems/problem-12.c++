//------------------------------------
//      Digital Root
//              INPUT: n = 99999
//              OUTPUT: 9
//              EXPLANATION: Sum of digits of 99999 is 45
//                           which is not a single digit number, hence
//                           sum of digit of 45 is 9 which is a single
//                           digit number.
//------------------------------------

#include<iostream>

using namespace std;

int find(int n){
    if(n==0){
        return n;
    }
    int res = find(n/10) + (n%10);
    return find(res/10) + (res%10);
}

int main(){
    int n = 9999;

    if(n<10){
        return n;
    }
    int res = find(n);
    cout<<res<<endl;

}