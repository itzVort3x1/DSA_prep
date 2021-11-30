//------------------------------------
//      Number of set bits in A and B.
//      Ex: INPUT: A = 2, b = 3
//          OUTPUT: 3
//          EXPLANATION: 2 in binary = 10
//                       3 in binary = 11
//                       total set bits = 3
//------------------------------------

#include<iostream>
using namespace std;

int calculateSetBits(int num){
    int count = 0;
    while(num!=0){
        if(num&1){
            count++;
        }
        num = num >> 1;
    }
    return count;
}

int main() {
    int a, b;
    cin>>a>>b;

    int setBitsinNum1 = calculateSetBits(a);
    int setBitsinNum2 = calculateSetBits(b);

    cout<<"The number of set bits in A & B is: "<< setBitsinNum1 + setBitsinNum2 << endl;
    return 0;
}