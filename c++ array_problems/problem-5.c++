//------------------------------------
//      Find duplicates in an array
//      Ex: INPUT: arr={1, 2, 3, 4, 2, 7, 8, 8, 3}
//          output: 2, 3, 8
//------------------------------------

#include<iostream>

using namespace std;

int main() {
    int arr[9] = {1, 2, 3, 4, 2, 7, 8, 8, 3};

    for(int i=0; i<9-1; i++){
        for(int j=i+1; j<9; j++){
            if(arr[i] == arr[j]){
                cout<<arr[i]<<" ";
            }
        }
    }
}