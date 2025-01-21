//------------------------------------
//      Unique Binary Search Trees (Catalan Number)
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveRec(int n){
    if(n <= 1){
        return 1;
    }

    int ans = 0;

    for(int i = 1; i<=n; i++){
        ans += solveRec(i-1) * solveRec(n-i);
    }

    return ans;
}

int solveDp(int n, vector<int> &dp){
    if(n <= 1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = 0;

    for(int i = 1; i<=n; i++){
        ans += solveDp(i-1, dp) * solveDp(n-i, dp);
    }

    dp[n] = ans;

    return dp[n];
}

int solveTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }

    return dp[n];
}

int main() {
    int n = 3;
    vector<int> dp(n+1, -1);
    
    int ansRec = solveRec(n);
    int ansDp = solveDp(n, dp);
    int ansTab = solveTab(n);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp is: " << ansDp << endl;
    cout << "Answer using tab is: " << ansTab << endl;

    return 0;
}