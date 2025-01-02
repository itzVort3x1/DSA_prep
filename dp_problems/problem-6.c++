//------------------------------------
//      Cut Rod into Segments of X, Y, Z 
//      Ex: INPUT: n = 7 
//                 x = 5
//                 y = 2
//                 z = 2
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solveRec(int n, int x, int y, int z){
    if(n == 0){
        return 0;
    }

    if(n < 0){
        return INT_MIN;
    }

    int a = solveRec(n-x, x, y, z) + 1;
    int b = solveRec(n-y, x, y, z) + 1;
    int c = solveRec(n-z, x, y, z) + 1;

    int ans = max(a, max(b, c));
    return ans;
}

int solveMem(int n, int x, int y, int z, vector<int> &dp){
    if(n == 0){
        return 0;
    }

    if(n < 0){
        return INT_MIN;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int a = solveMem(n-x, x, y, z, dp) + 1;
    int b = solveMem(n-y, x, y, z, dp) + 1;
    int c = solveMem(n-z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

int solveTab(int n, int x, int y, int z){

    vector<int> dp(n+1, -1);

    dp[0] = 0; 

    for(int i = 1; i <=n; i++){
        if(i-x >= 0 && dp[i-x] != -1){
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        if(i - y >= 0 && dp[i-x] != -1){
            dp[i] = max(dp[i], dp[i-y] + 1);
        }
        if(i - z >= 0 && dp[i-x] != -1){
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }

    if(dp[n] < 0){
        return 0;
    }else {
        return dp[n];
    }
}

int solveSpace(int n, int x, int y, int z){

    vector<int> dp(n+1, -1);

    dp[0] = 0; 

    for(int i = 1; i <=n; i++){
        if(i-x >= 0 && dp[i-x] != -1){
            dp[i] = max(dp[i], dp[i-x] + 1);
        }
        if(i - y >= 0 && dp[i-x] != -1){
            dp[i] = max(dp[i], dp[i-y] + 1);
        }
        if(i - z >= 0 && dp[i-x] != -1){
            dp[i] = max(dp[i], dp[i-z] + 1);
        }
    }

    if(dp[n] < 0){
        return 0;
    }else {
        return dp[n];
    }
}


int main() {

    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    vector<int> dp(n+1, -1);

    int ansRec = solveRec(n, x, y, z);
    int ansMem = solveMem(n, x, y, z, dp);
    int ansTab = solveTab(n, x, y, z);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using Memoization DP is: " << ansMem << endl;
    cout << "Answer using Tab DP is: " << ansTab << endl;

    return 0;
}