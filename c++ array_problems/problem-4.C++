//------------------------------------
//      Find unique element in the array
//      Ex: INPUT: arr={2,4,2,3,4,5,3}
//          OUTPUT: 4
//------------------------------------

#include<iostream>
using namespace std;

void findUnique(int arr[], int n){
    int ans;
    for(int i=0; i<n; i++){
        ans = ans^arr[i];
    }
    cout<<"The unique element in the array is: "<<ans<<endl;
}

int main(){
    int arr[7] = {2,4,2,3,4,5,3};

    findUnique(arr, 7);
}