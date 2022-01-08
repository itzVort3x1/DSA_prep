//------------------------------------
//      PROBLEM LINK: https://leetcode.com/problems/search-a-2d-matrix/
//      Binary Search a 2D Matrix
//      Ex: INPUT: n = 3 4 11
//                     2 12 1 
//                     7 8  7
//                 target = 12
//          OUTPUT:  true
//------------------------------------

#include<iostream>
#include<vector>

using namespace std;

int main() {
    int arr[3][4];
    int target;

    cout<<"Enter your array elements: "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Enter the element you want to find: ";
    cin>>target;

    int rows = 3;
    int cols = 4;

    int start = 0;
    int end = rows*cols - 1;

    int mid = start + (end-start)/2;

    int flag = 0;

    while(start<end){
        int element = arr[mid/cols][mid%cols];

        if(element == target){
            flag=1;
        }

        if(element < target){
            end = mid - 1;
        }else {
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    } 
    if(flag){
        cout<<"Element is found in the 2D array.";

    }else {
        cout<<"Element is not found in the 2D array";
    }
}