//------------------------------------
//      Array Intersection
//      Ex: INPUT: arr1={1, 2, 2, 2, 3, 4} arr2={2, 2, 3, 3}
//          OUTPUT: 3
//------------------------------------

#include<iostream>
using namespace std;

int main(){
    int arr1[6] = {1, 2, 2, 2, 3, 4};
    int arr2[4] = {2, 2, 3, 3};

    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            if(arr1[i] == arr2[j]){
                cout<<arr2[j]<<" ";
                arr2[j] = INT8_MIN;
                break;
            }
        }
    }
    cout<<endl;
    return 0;
}