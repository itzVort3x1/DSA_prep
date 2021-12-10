#include<iostream>
using namespace std;

int main(){
    int arr[5] = {4,6,1,3,7};

    for(int i = 0; i<5-1; i++){
        for(int j = i+1; j<5; j++){
            if(arr[j]<arr[i]){
        		swap(arr[j], arr[i]);
            }
        }
    }

    //Printing the result;
    for(int i=0 ;i<5; i++){
        cout<<arr[i]<<" ";
    }
}