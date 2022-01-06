//------------------------------------
//      Largest Row sum
//      Ex: INPUT: n = 3 4 11 -> 18
//                     2 12 1 -> 15
//                     7 8  7 -> 22
//          OUTPUT: 2
//          EXPLANATION: 18 15 22
//                       The largest among these 3 is 22 which is on row 2.
//------------------------------------

#include<iostream>

using namespace std;

void largestRowSum(int arr[][3], int row, int col){
    int maxi = INT_MIN;
    int rowIndex = -1;

    for(int i=0; i<row; i++){
        int ans = 0;
        for(int j=0; j<col; j++){
            ans += arr[i][j];
        }
        if(ans > maxi){
            maxi = ans;
            rowIndex = i;
        }
        ans=0;
    }

    cout<<"The max sum is "<< maxi << " on row -> "<< rowIndex << endl;
}

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
    cout<<endl;
    largestRowSum(arr, 3, 3);

    return 0;
}