//------------------------------------
//      Split an array into two equal Sum subarrays
//      Ex: Input : Arr[] = { 1 , 2 , 3 , 4 , 5 , 5  }
//          Output :  { 1 2 3 4 } 
//                    { 5 , 5 }
//------------------------------------

#include <iostream>
using namespace std;

int main() {
    int Arr[] = {1, 2, 3, 4, 5, 5};
    int n = 6;

    bool found = false;

    int leftSum = 0;
    for(int i = 0; i<n; i++){
        leftSum += Arr[i];
    }

    int rightSum = 0;

    for(int i = n-1; i>0; i--){
        rightSum += Arr[i];
        leftSum -= Arr[i];

        if(rightSum == leftSum){
            found = true;
        }
    }

    if(found){
        cout << "Two sub arrays with equal sum are present" << endl;
    }else{
        cout << "No such sub arrays found" << endl;
    }
    return 0;
}