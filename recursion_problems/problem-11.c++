//------------------------------------

//      PROBLEM LINK: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
//      Rat in a Maze problem-1
//              INPUT: N = 4
//                     m[][] = {{1, 0, 0, 0},
//                              {1, 1, 0, 1}, 
//                              {1, 1, 0, 0},
//                              {0, 1, 1, 1}}
//              OUTPUT: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//------------------------------------

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>

using namespace std;

bool isSafe(int x, int y, vector<vector<int>> visited, vector<vector<int>> m, int n){
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1){
            return true;
        }else {
            return false;
        }
}

void solve(vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> visited, string path, int x, int y){

    //base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    //4 choices
    //down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, visited, m, n)){
        path.push_back('D');
        solve(m,n,ans, visited, path, newx, newy);
        path.pop_back();
    }

    //left
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, visited, m, n)){
        path.push_back('L');
        solve(m,n,ans, visited, path, newx, newy);
        path.pop_back();
    }

    //right
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, visited, m, n)){
        path.push_back('R');
        solve(m,n,ans, visited, path, newx, newy);
        path.pop_back();
    }

    //up
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, visited, m, n)){
        path.push_back('U');
        solve(m,n,ans, visited, path, newx, newy);
        path.pop_back();
    }

    visited[x][y] =0;
}

int main(){
    int N =4;
    vector<vector<int>> m = {{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};

    vector<string> ans;

    if(m[0][0] == 0){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
    }

    string path = "";
    vector<vector<int>> visited;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            visited[i][j] = 0;
        }
    }
    int srcx = 0;
    int srcy = 0;

    solve(m,N,ans, visited, path, srcx, srcy);
    sort(ans.begin(), ans.end());


    for(int i=0; i<N; i++){
        cout<<ans[i]<<" ";
    }
}