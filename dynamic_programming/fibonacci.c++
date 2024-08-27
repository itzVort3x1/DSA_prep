#include<iostream>
#include<vector>
using namespace std;

int solveUsingRecurstion(int n){
     if(n == 0 || n == 1){
          return n;
     }

     int ans = solveUsingRecurstion(n-1) + solveUsingRecurstion(n-2);
     return ans;
}

// recursion + memo = TOP-DOWN approach
int solveUsingMemoisation(int n, vector<int> &dp) {
     if(n == 0 || n == 1){
          return n;
     }

     if(dp[n] != - 1){
          return dp[n];
     }

     dp[n] = solveUsingMemoisation(n-1, dp) + solveUsingMemoisation(n-2, dp);
     return dp[n];
}

int solveUsingTabulation(int n, vector<int> &dp){
     dp[0] = 0;
     dp[1] = 1;

     for(int i = 2; i<= n; i++){
          dp[i] = dp[i-1] + dp[i-2];
     }

     return dp[n];
}

int main() {
     int ans = solveUsingRecurstion(4);
     cout << "Printing ans using recursion: " <<  ans << endl;

     vector<int> dp(4+1, -1);
     int ans1 = solveUsingMemoisation(4, dp);
     cout << "Priting ans using Top-Down Approach: " << ans1 << endl;

     vector<int> dp2(4+1, -1);
     int ans2 = solveUsingMemoisation(4, dp2);
     cout << "Priting ans using Bottom-Up Approach: " << ans2 << endl;
}