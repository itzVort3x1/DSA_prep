//------------------------------------
//      N-Queen problem
//      GFG link: https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1?page=1&status[]=bookmarked&sortBy=submissions
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

void addSolution(vector<vector<int> > &board, vector<vector<int> > &ans, int n){
     vector<int> temp;
     for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
               if(board[i][j] == 1){
                    temp.push_back(j+1);
               }
          }
     }
     ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int> > &board, int n){
     int x = row;
     int y = col;

     //checking for the same row;
     while(y>=0){
          if(board[x][y] == 1){
               return false;
          }
          y--;
     }

     //checking for the upper left diagonal
     x = row;
     y = col;
     while(x>=0 && y >= 0){
          if(board[x][y] == 1){
               return false;
          }
          x--;
          y--;
     }

     //checking for the lower left diagonal
     x = row;
     y = col;
     while(x < n && y >= 0){
          if(board[x][y] == 1){
               return false;
          }
          x++;
          y--;
     }

     return true;
}


void solve(int col, vector<vector<int> > &board, vector<vector<int> > &ans, int n){
     //base case
     if(col == n){
          addSolution(board, ans, n);
          return;
     }

     for(int row=0; row<n; row++){
          if(isSafe(row, col, board, n)){
               board[row][col] = 1;
               solve(col+1, board, ans, n);
               board[row][col] = 0;
          }
     }

}

int main(){
     int n;
     cout << "Enter the number of queens: ";
     cin >> n;

     vector<vector<int> > board(n, vector<int>(n, 0));
     vector<vector<int> > ans;

     solve(0, board, ans, n);

     for(int i=0; i<ans.size(); i++){
          for(int j=0; j<ans[i].size(); j++){
               cout << ans[i][j] << " ";
          }
          cout << endl;
     }

}