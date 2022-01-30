//------------------------------------
//      Lucky number
//              INPUT: n = 9 p = 9
//              OUTPUT: 387420489
//              EXPLANATION: 387420489 is the value 
//                           obtained when 9 is raised to the 
//                           power of 9.
//------------------------------------

#include<iostream>

using namespace std;

int power(int n, int p){
    if(p==0){
        return 1;
    }
    return n*power(n,p-1);
}

int main(){
    int n=9, p=9;

    int res = power(n,p);

    cout<<"The ans is: "<<res<<endl;
}