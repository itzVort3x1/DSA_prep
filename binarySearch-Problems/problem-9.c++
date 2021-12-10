//------------------------------------
//      painter's partition problem
//      Ex: INPUT: arr = {5,5,5,5}, k = 2
//          OUTPUT: 10
//          EXPLANATION: Similar to Book allocation problem. Reffer problem-8.
//------------------------------------
// incomplete.
#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int mid, int m){
    int painterCount = 1;
    int painterSum = 0;

    for(int i=0; i<n; i++){
        if(painterSum + arr[i] <= mid){
            painterSum +=arr[i];
        }else {
            painterCount++;
            if(painterCount > m || arr[i] > mid){
                return false;
            }
            painterSum = arr[i];
        }
    }
    return true;

}

int main(){
    int arr[4] = {5,5,5,5};
    int sum = 0;

    for(int i=0; i<4; i++){
        sum += arr[i];
    }
    int s = 0;
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(isPossible(arr, 4, mid, 2)){
            ans = mid;
            s = mid + 1;
        }else {
            e = mid -1;
        }
        mid = s + (e-s)/2;
    }
    cout<<"The max is: "<<ans<<endl;
    return 0;
}