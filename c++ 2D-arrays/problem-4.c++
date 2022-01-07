//------------------------------------
//      Wave print
//      Ex: INPUT: n = 3 4 11
//                     2 12 1 
//                     7 8  7
//          OUTPUT: 3 2 7 8 12 4 11 1 7
//------------------------------------

#include<iostream>

using namespace std;

int main(){
    int arr[3][3];

    cout<<"Enter the array elements: "<<endl;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"wave patter of the 2D-array is: "<<endl;

    for(int i=0; i<3; i++){
        if(i&1){
            for(int j=3-1; j>=0; j--){
                cout<<arr[i][j]<<" ";
            }
        }else {
            for(int j=0; j<3; j++){
                cout<<arr[i][j]<<" ";
            }
        }
    }

    return 0;
}