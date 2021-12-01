//------------------------------------
//      Nth fibonacci number
//      Ex: INPUT: n = 5
//          OUTPUT: 3
//          EXPLANATION: fibonacci sequence = 0, 1, 1, 2, 3, 4, 8, 13.......
//                       5th term in the sequence is 3.
//------------------------------------

#include<iostream>
using namespace std;

int fibo(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int a=0,b=1;
    int ans;
   for(int i=2;i<n;i++){
       ans=a+b;
       a=b;
       b=ans;
   }
    return ans;
}

int main(){
    int n;

    cin>>n;
    cout<<n<<"th fibonacci no is"<<fibo(n)<<endl;
    return 0;
}
