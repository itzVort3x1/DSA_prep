//------------------------------------
//      Rotate an array if a position K is given.
//      Ex: INPUT: arr={1,2,3,4,5,6,7} k=3
//          OUTPUT: 5 6 7 1 2 3 4
//------------------------------------

#include<iostream>

using namespace std;

int main(){
    int arr[7] = {1,2,3,4,5,6,7};
    int k = 3;

    int temp[7] = {0};

    for(int i=0; i<7; i++){
        temp[(i+k)%7] = arr[i];
    }

    for(int i=0; i<7; i++){
        cout<<temp[i]<<" ";
    }
}