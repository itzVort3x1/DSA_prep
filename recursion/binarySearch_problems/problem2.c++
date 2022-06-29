//------------------------------------
//      Find the total number of occurances 
//      Ex: INPUT: arr = {1,2,3,3,3,3,3,3,5,8}
//          OUTPUT: 6
//          EXPLANATION: 3 occurs 6 times in the array.
//------------------------------------

#include<iostream>
using namespace std;

int first(int arr[], int low, int high, int x, int n){
     if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}

int last(int arr[], int low, int high, int x, int n){
     if(high >= low){
          int mid = low + (high - low)/2;
          if((mid == n-1 || x < arr[mid + 1]) && arr[mid] == x){
               return mid;
          }else if(x < arr[mid]){
               return last(arr, low, (mid - 1), x, n);
          }else {
               return last(arr, (mid + 1), high, x, n);
          }
     }
     return -1;
}

int main(){
    int arr[10] = {1,2,3,3,3,3,3,3,5,8};
    int n = sizeof(arr)/sizeof(int);

    int total = last(arr, 0, 9, 3, n) - first(arr, 0, 9, 3, n) + 1;

    cout<<"The total number of times 3 occurs in the array is : "<<total<<endl;

    return 0;
}