//------------------------------------
//      Josephus problem
//              INPUT: N = 3, k=2
//              OUTPUT: 3
//              EXPLANATION: There are 3 persons so 
//                           skipping 1 person i.e 1st person 2nd 
//                           person will be killed. Thus the safe 
//                           position is 3.
//------------------------------------

#include<iostream>

using namespace std;

int josephus(int n, int k){
    if(n==0){
        return 1;
    }

    return (josephus(n-1, k) + k-1)%n+1;
}

int main(){
    int N=3, k=2;

    int res = josephus(N, k);

    cout<<"The safe position is: "<<res<<" ";
}
