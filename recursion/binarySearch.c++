#include<iostream>

using namespace std;

bool binarySearch(int arr[], int s, int e, int key){
    if(s>e){
        return false;
    }
    int mid = s + (e-s)/2;

    if(arr[mid] == key){
        return true;
    }

    if(arr[mid] < key){
        return binarySearch(arr, mid+1, e, key);
    }else {
        return binarySearch(arr, s, mid-1, key);
    }
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    int key;
    cin>>key;
    int start = 0;
    int end = 6;
    if(binarySearch(arr, start, end, key)){
        cout<<"The key is present in the array."<<endl;
    }else {
        cout<<"The key is not present in the array."<<endl;
    }
}