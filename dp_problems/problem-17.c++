//------------------------------------
//      Longest Increasing subsequence
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<int> arr, int n, int curr, int prev){
    if(curr == n){
        return 0;
    }

    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev]){
        include = 1 + solveRec(arr, n, curr+1, curr);
    }

    int exclude = solveRec(arr, n, curr+1, prev);

    int ans = max(include, exclude);

    return ans;
}

int solveMem(vector<int> arr, int n, int curr, int prev, vector<vector<int>> &dp){
    if(curr == n){
        return 0;
    }

    if(dp[curr][prev+1] != -1){
        return dp[curr][prev+1];
    }

    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev]){
        include = 1 + solveRec(arr, n, curr+1, curr);
    }

    int exclude = solveRec(arr, n, curr+1, prev);

    dp[curr][prev + 1] = max(include, exclude);

    return dp[curr][prev+1];
}

int solveTab(vector<int> arr, int n){
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int curr = n-1; curr>=0; curr--){
        for(int prev = curr-1; prev>=-1; prev--){
            int include = 0;
            if(prev == -1 || arr[curr] > arr[prev]){
                include = 1 + dp[curr+1][curr+1];
            }

            int exclude = dp[curr+1][prev + 1];

            dp[curr][prev + 1] = max(include, exclude);
        }
    }

    return dp[0][0];
}


int main() {
    vector<int> arr = {5,8,3,7,9,1};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));

    int ansRec = solveRec(arr, n, 0, -1);
    int ansMem = solveMem(arr, n, 0, -1, dp);
    int ansTab = solveTab(arr, n);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using Dp Mem is: " << ansMem << endl;
    cout << "Answer using tab is: " << ansTab << endl;

    return 0;
}
