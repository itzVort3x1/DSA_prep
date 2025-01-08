//------------------------------------
//      Min Score Triangulation of Polygon
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &v, int i, int j){
    if(i + 1 == j){
        return 0;
    }

    int ans = INT_MAX;
    for(int k=i+1; k<j; k++){
        ans = min(ans, v[i]*v[j]*v[k] + solveRec(v,i,k) + solveRec(v,k,j));
    }

    return ans;

}

int solveMem(vector<int> &v, int i, int j, vector<vector<int>> &dp){
    if(i + 1 == j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = INT_MAX;
    for(int k=i+1; k<j; k++){
        ans = min(ans, v[i]*v[j]*v[k] + solveMem(v,i,k,dp) + solveMem(v,k,j,dp));
    }

    dp[i][j] = ans;

    return dp[i][j];

}

int solveTab(vector<int> &v){
    int n = v.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n -1; i>=0; i--){
        for(int j = i+2; j<n; j++){
            int ans = INT_MAX;
            for(int k=i+1; k<j; k++){
                ans = min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][n-1];
}

int solveTab(vector<int> &v){
    int n = v.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n -1; i>=0; i--){
        for(int j = i+2; j<n; j++){
            int ans = INT_MAX;
            for(int k=i+1; k<j; k++){
                ans = min(ans, v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]);
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][n-1];
}

int main() {
    vector<int> values = {1,2,3};
    int n = values.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int ansRec = solveRec(values, 0, values.size() -1);
    int ansDp = solveMem(values, 0, values.size() -1, dp);
    int ansTab = solveTab(values);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp mem is: " << ansDp << endl;
    cout << "Answer using Tab is: " << ansTab << endl;

    return 0;
}