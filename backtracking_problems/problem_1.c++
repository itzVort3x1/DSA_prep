//------------------------------------
//      N-Queen problem
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

void addSolution(vector<vector<int> > &board, vector<vector<int> > &ans, int n){
     vector<int> temp;
     for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){
               if(board[i][j] == 1){
                    temp.push_back(j);
               }
          }
     }
     ans.push_back(temp);
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