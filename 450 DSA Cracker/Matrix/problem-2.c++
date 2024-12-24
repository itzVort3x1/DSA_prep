//------------------------------------
//      Search a 2D Matrix
//      Link: https://leetcode.com/problems/search-a-2d-matrix/description/
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    int target = 3;

    int row = matrix.size();
    int col = matrix[0].size();
    int n = row*col;

    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;

    while(s <= e){
        int rowIndex = mid /col;
        int colIndex = mid%col;
        int currNum = matrix[rowIndex][colIndex];

        if(currNum == target){
            cout << "The target is present in the matrix" << endl;
            return 0;
        }else if(target > currNum){
            s = mid + 1;
        }else {
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }

    cout << "The target is not present in the matrix" << endl;

    return 0;
}