//------------------------------------
//      Sorted matrix
//      Link: https://www.geeksforgeeks.org/problems/sorted-matrix2333/1
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> Mat = {{10,20,30,40}, {15,25,35,45}, {27,29,37,48}, {32,33,39,50}};
    int N = 4;

    vector<int> v;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            v.push_back(Mat[i][j]);
        }
    }
        
    sort(v.begin(), v.end());
        
    int c = 0;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            Mat[i][j] = v[c++];
        }
    }
    
    cout << "The sorted matrix is: " << endl;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            cout << Mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;

}