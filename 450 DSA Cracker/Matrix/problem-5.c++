//------------------------------------
//      Rotate by 90 degree
//      Link: https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};

    int n = mat[0].size();
    for(int i = 0; i<n; i++){
        for(int j =i ;j<n;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n/2; j++){
            swap(mat[i][j], mat[i][n-j-1]);
        }
    }

    cout << "The rotated matrix is: " << endl;

    for(int i = 0; i<n; i++){
        for(int j =0 ;j<n;j++){
            cout << mat[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}