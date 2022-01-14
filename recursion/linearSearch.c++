#include<iostream>

using namespace std;

bool searchArr(int arr[], int n, int key){
    if(n==0){
        return 0;
    }
    if(arr[0]==key){
        return 1;
    }else {
        bool rem = searchArr(arr+1, n-1, key);
        return rem;
    }
    
}

int main(){
    int arr[5] = {1,2,3,4,5};

    int ans = searchArr(arr, 5, 3);

    if(ans){
        cout<<"Found element"<<endl;
    }else {
        cout<<"Element not found"<<endl;
    }
}