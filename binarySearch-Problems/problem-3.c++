//------------------------------------
//      Peak Index in a Mountain Array
//      Ex: INPUT: arr = [24,69,100,99,79,78,67,36,26,19]
//          OUTPUT: 2
//          EXPLANATION: The peak is at index 2. or we can say that the largest element is at 100.
//------------------------------------

#include<iostream>
using namespace std;

int findPeak(int arr[], int n){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){
        if(arr[mid] < arr[mid + 1]){
            s = mid +1;
        }else {
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return s;
}

int main() {
    int arr[11] = {24,69,72,100,99,79,78,67,36,26,19};

    cout << "The peak is at index: "<< findPeak(arr, 11)<<endl;

    return 0;
}