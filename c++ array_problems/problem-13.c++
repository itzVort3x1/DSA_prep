//------------------------------------
//      Move zeros to the right
//      Ex: INPUT: arr={2,0,1,3,0,0,0} 
//          OUTPUT: 2 1 3 0 0 0 0
//------------------------------------

#include<iostream>

using namespace std;

int main(){
    int arr[7] = {2,0,1,3,0,0,0};

    int i=0;

    for(int j=0; j<7; j++){
        if(arr[j] != 0){
            swap(arr[j], arr[i]);
            i++;
        }
    }

    for(int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
