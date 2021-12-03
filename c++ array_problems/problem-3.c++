//------------------------------------
//      Swap alternative
//      Ex: INPUT: arr={2,5,6,8,12,9}
//          OUTPUT: 5,2,8,6,9,12
//------------------------------------

#include<iostream>
using namespace std;

void swapAlternate(int arr[], int n){
    for(int i=0; i<n; i+=2){
        if(i+1 < n){
            swap(arr[i], arr[i+1]);
        }
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[6] = {2,5,6,8,9,12};
    int brr[5] = {42,51,6,8,12};

    swapAlternate(arr, 6);
    swapAlternate(brr, 5);

    printArray(arr, 6);
    printArray(brr, 5);
}