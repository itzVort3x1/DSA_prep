//------------------------------------
//      Find the total number of occurances 
//      Ex: INPUT: arr = {1,2,3,3,3,3,3,3,5,8}
//          OUTPUT: 6
//          EXPLANATION: 3 occurs 6 times in the array.
//------------------------------------

#include<iostream>
using namespace std;

int firstOcc(int arr[], int key, int n){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    int ans = -1;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            e = mid-1;
        }else if(key > arr[mid]){
            s = mid + 1;

        }else if(key < arr[mid]){
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }

    return ans;
}

int lastOcc(int arr[], int key, int n){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    int ans = -1;

    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            s = mid+1;
        }else if(key > arr[mid]){
            s = mid + 1;

        }else if(key < arr[mid]){
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }

    return ans;
}

int main(){
    int arr[10] = {1,2,3,3,3,3,3,3,5,8};

    int total = lastOcc(arr, 3, 10) - firstOcc(arr,3,10) + 1;

    cout<<"The total number of times 3 occurs in the array is : "<<total<<endl;

    return 0;
}