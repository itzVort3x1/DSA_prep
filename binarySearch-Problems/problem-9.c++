//------------------------------------
//      painter's partition problem
//      Ex: INPUT: arr = {5,5,5,5}, k = 2
//          OUTPUT: 10
//          EXPLANATION: Similar to Book allocation problem. Reffer problem-8.
//------------------------------------

#include<iostream>
using namespace std;

int main(){
    int arr[4] = {5,5,5,5};
    int sum = 0;

    for(int i=0; i<4; i++){
        sum += arr[i];
    }
}