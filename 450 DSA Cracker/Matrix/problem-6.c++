//------------------------------------
//      Kth element in matrix
//      Link: https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1
//------------------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> mat = {{16, 28, 60, 64},{22, 41, 63, 91},{27, 50, 87, 93},{36, 78, 87, 94 }};
    int n = 4;
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            pq.push(mat[i][j]);
        }
    }
    
    int count = 1;
    while(!pq.empty()){
        if(count == k){
            cout << "Kth smallest element is: " << pq.top() << endl;
            return 0;
        }
        pq.pop();
        count++;
    }
    
    cout << endl;

    return 0;
}