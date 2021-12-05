//------------------------------------
//      sort 0's and 1's
//      Ex: INPUT: arr={0,1,0,1,1,0,0}
//          OUTPUT: 0,0,0,0,1,1,1
//------------------------------------

#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortOne(int arr[], int n){
    int left = 0, right =n-1;
    while(left<right){
        while(arr[left] == 0){
            left++;
        }
        while(arr[right] == 1){
            right--;
        }
        if(left<right){
            swap(arr[left], arr[right]);
            left++;            
            right--;
        }
    }
}

int main() {
    int arr[7] = {0,1,0,1,1,0,0};

    sortOne(arr, 7);
    printArray(arr, 7);

    return 0;
}