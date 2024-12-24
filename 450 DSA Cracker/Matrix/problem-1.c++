//------------------------------------
//      Spirally traversing a matrix
//      Link: https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> mat = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};

    vector<int> ans;
    int totalElements = mat.size() * mat[0].size();

    int startRow = 0;
    int endRow = mat.size() - 1;
    int startCol = 0;
    int endCol = mat[0].size() - 1;

    int count = 0;

    while(count < totalElements){
        for(int i = startCol; i <= endCol && count < totalElements; i++){
            ans.push_back(mat[startRow][i]);
            count++;
        }
        startRow++;

        for(int i = startRow; i <= endRow && count < totalElements; i++){
            ans.push_back(mat[i][endCol]);
            count++;
        }
        endCol--;

        for(int i = endCol; i >= startCol && count < totalElements; i--){
            ans.push_back(mat[endRow][i]);
            count++;
        }
        endRow--;

        for(int i = endRow; i >= startRow && count < totalElements; i--){
            ans.push_back(mat[i][startCol]);
            count++;
        }
        startCol++;
    }

    cout << "Spirally traversed matrix is: ";
    for(int num: ans){
        cout << num << " ";
    }

    cout << endl;

    return 0;

}