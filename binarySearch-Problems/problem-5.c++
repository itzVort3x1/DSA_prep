//------------------------------------
//      Search element in sorted and rotated array
//      Ex: INPUT: arr = {6,7,9,1,2,3,4,5} key = 4
//          OUTPUT: 6
//          EXPLANATION: The element 4 is at index 6. This is a sorted and rotated array.
//------------------------------------

#include<iostream>
using namespace std;

int getPivot(int arr[], int n){
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

int binarySearch(int arr[], int n, int k){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(arr[mid] == k){
            ans = mid;
        }
        if(k > arr[mid]){
            s = mid+1;
        }else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    int arr[8] = {6,7,9,1,2,3,4,5};

    int pivot = getPivot(arr, 8);

    cout<<"The element is at the index: "<<binarySearch(arr, 8, 4)<<endl;

    return 0;
}