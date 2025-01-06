//------------------------------------
//      Perfect Squares Problem
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solveRec(int n){
    if(n == 0){
        return 0;
    }   

    int ans = n;
    for(int i = 1; i*i<n; i++){
        ans = min(ans, 1 + solveRec(n-i*i));
    }

    return ans;
}

int solveDp(int n, vector<int> &dp){
    if(n == 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }   

    int ans = n;
    for(int i = 1; i*i<=n; i++){
        ans = min(ans, 1 + solveDp(n-i*i, dp));
    }

    dp[n] = ans;

    return dp[n];
}

int solveTab(int n){
    vector<int> dp(n+1, INT_MAX);

    dp[0] = 0;
    
    for(int i = 1; i<=n; i++){
        for(int j=1; j*j<=n; j++){
            int temp = j*j;
            if(i-temp >= 0){
                dp[i] = min(dp[i], 1+ dp[i-temp]);
            }
        }
    }

    return dp[n];
}

int main() {
    int n = 100;

    vector<int> dp(n+1, -1);

    // int ansRec = solveRec(n);
    int ansDp = solveDp(n, dp);
    int ansTab = solveTab(n);

    // cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using Dp is: " << ansDp << endl;
    cout << "Answer using tab is: " << ansTab << endl;

    return 0;
}