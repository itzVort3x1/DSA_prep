//------------------------------------
//      Row-wise sum
//      Ex: INPUT: n = 3 4 11 -> 18
//                     2 12 1 -> 15
//                     7 8  7 -> 22
//          OUTPUT: 18 15 22
//          EXPLANATION: sum of elements in row 1st row
//                          3+4+11 = 18
//------------------------------------

#include<iostream>

using namespace std;

int main() {
    int arr[3][3];

    cout<<"Enter your 2D-array: "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    cout<<"Your 2D-array is: "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int ans = 0;

    cout<<"Your answer is: ";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            ans += arr[i][j];
        }
        cout<<ans<<" ";
        ans=0;
    }

    return 0;
}