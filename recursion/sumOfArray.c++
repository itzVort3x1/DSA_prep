#include<iostream>

using namespace std;

int sumOfArray(int arr[], int n){
    int sum=0;
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }

    return arr[0] + sumOfArray(arr+1, n-1);
    
}

int main(){
    int arr[5] = {1,2,3,4,5};

    int ans = sumOfArray(arr, 5);

    cout<<ans<<endl;
}