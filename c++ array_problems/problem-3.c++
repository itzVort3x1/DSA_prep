//------------------------------------
//      Swap alternative
//      Ex: INPUT: arr={2,5,6,8,12,9}
//          OUTPUT: 5,2,8,6,9,12
//------------------------------------

#include<iostream>
using namespace std;

void swap(int arr[], int n){
    int start = 0;
    int end = 1;

    while(end<=n){
        swap(arr[start], arr[end]);
        start+=2;
        end+=2;
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[6] = {2,5,6,8,12,9};

    swap(arr, 6);

    printArray(arr, 6);
}