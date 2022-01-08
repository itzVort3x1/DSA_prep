//------------------------------------
//      PROBLEM LINK: https://leetcode.com/problems/search-a-2d-matrix-ii/
//      Binary Search a 2D Matrix Level-2
//      Ex: INPUT: n = 1 4 7 11 15
//                     2 5 8 12 19
//                     3 6 9 16 22
//                     10 13 14 17 24
//                     18 21 23 26 30
//                 target = 12
//          OUTPUT:  true
//------------------------------------

#include<iostream>
#include<vector>

using namespace std;

int main(){

    int target;
    int flag = 0;
    vector<vector<int>> arr = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    cout<<"Enter the element you want to find: ";
    cin>>target;

    int row = arr.size();
    int col = arr[0].size();

    int rowIndex = 0;
    int colIndex = col-1;

    while(rowIndex < row && colIndex >=0){
        int element = arr[rowIndex][colIndex];

        if(element == target){
            flag = 1;
        }

        if(element < target){
            rowIndex++;
        }else {
            colIndex--;
        }
    }

    if(flag){
        cout<<"Element is Present in the matrix."<<endl;
    }else {
        cout<<"Element in not Present in the matrix."<<endl;
    }

    return 0;
}