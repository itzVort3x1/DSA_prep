//------------------------------------
//      Find Pivot in an array
//      Ex: INPUT: arr = {7,9,1,2,3} Rotated and sorted array.
//          OUTPUT: 2
//          EXPLANATION: The peak is at index 2. or we can say that the largest element is at 100.
//------------------------------------

#include<iostream>
using namespace std;

int findPivot(int arr[], int n){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main(){
    int arr[5] = {6,7,9,2,3};

    cout<< "Index of pivot element is: "<<findPivot(arr, 5)<<endl;

    return 0;
}