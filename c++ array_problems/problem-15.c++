//------------------------------------
//      Check if the array is sorted and rotated
//      Ex: INPUT: arr={4,5,6,7,1,2,3}
//          OUTPUT: Rotated and sorted
//------------------------------------

#include<iostream>

using namespace std;

int main(){
    int arr[7] = {4,5,6,7,1,2,3};

    int count = 0;
    for(int i=1; i<7; i++){
        if(arr[i-1] > arr[i]){
            count++;
        }
    }

    if(arr[7-1] > arr[0]){
        count++;
    }

    if(count <= 1 ){
        cout<<"Array is sorted and rotated"<<endl;
    }else{
        cout<<"Array is not sorted and rotated"<<endl;
    }
}