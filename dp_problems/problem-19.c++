//------------------------------------
//      Pizza with 3n slices
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveRec(int index, vector<int> &slices, int n){
    if(n == 0 || index >= slices.size()){
        return 0;
    }

    int incl = slices[index] + solveRec(index + 2, slices, n-1);
    int excl = solveRec(index + 1, slices, n);

    int ans = max(incl, excl);

    return ans;
}

int solveDp(int index, vector<int> &slices, int n, vector<vector<int>> &dp){
    if(n == 0 || index >= slices.size()){
        return 0;
    }

    if(dp[index][n] != -1) return dp[index][n];

    int incl = slices[index] + solveDp(index + 2, slices, n-1, dp);
    int excl = solveDp(index + 1, slices, n, dp);

    dp[index][n] = max(incl, excl);

    return dp[index][n];
}

int solveTab(vector<int> &slices){
    int k = slices.size();
    vector<vector<int>> dp1(k+2, vector<int> (k+2, 0));
    
    for(int index = k - 2; index >= 0; index--){
        for(int n = 1; n<=k/3; n++){
            int incl = slices[index] + dp1[index+2][n-1];
            int excl = dp1[index+1][n];

            dp1[index][n] = max(incl, excl);
        }
    }

    int case1 = dp1[0][k/3];

    vector<vector<int>> dp2(k+2, vector<int> (k+2, 0));
    
    for(int index = k - 1; index >= 1; index--){
        for(int n = 1; n<=k/3; n++){
            int incl = slices[index] + dp2[index+2][n-1];
            int excl = dp2[index+1][n];

            dp2[index][n] = max(incl, excl);
        }
    }

    int case2 = dp2[1][k/3];

    return max(case1, case2);
}

int main() {
    vector<int> slices={1,2,3,4,5,6};
    int k = slices.size();
    vector<vector<int>> dp1(k, vector<int> (k, -1));
    vector<vector<int>> dp2(k, vector<int> (k, -1));

    int case1 = solveRec(0, slices, k/3);
    int case2 = solveRec(1, slices, k/3);

    int ansRec = max(case1, case2);

    int case1Dp = solveDp(0, slices, k/3, dp1);
    int case2Dp = solveDp(1, slices, k/3, dp2);

    int ansDp = max(case1Dp, case1Dp);
    int ansTab = solveTab(slices);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp is: " << ansDp << endl;
    cout << "Answer using Tab is: " << ansTab << endl;

    return 0;
}