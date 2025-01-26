//------------------------------------
//      Longest Common Subsequence
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveRec(string text1, string text2, int i, int j){
    if(i == text1.length() || j == text2.length()){
        return 0;
    }

    int ans = 0;
    if(text1[i] == text2[j]){
        ans = 1 + solveRec(text1, text2, i+1, j+1);
    }else {
        ans = max(solveRec(text1, text2, i+1, j), solveRec(text1, text2, i, j+1));
    }

    return ans;

}

int solveDp(string text1, string text2, int i, int j, vector<vector<int>> &dp){
    if(i == text1.length() || j == text2.length()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 0;
    if(text1[i] == text2[j]){
        ans = 1 + solveDp(text1, text2, i+1, j+1, dp);
    }else {
        ans = max(solveDp(text1, text2, i+1, j, dp), solveDp(text1, text2, i, j+1, dp));
    }

    return dp[i][j] = ans;
}

int solveTab(string text1, string text2 ){
    vector<vector<int>> dp(text1.length() +1, vector<int>(text2.length() + 1, 0));

    for(int i=text1.length() - 1; i>=0; i--){
        for(int j = text2.length()-1; j>=0; j--){
            int ans = 0;
            if(text1[i] == text2[j]){
                ans = 1 + dp[i+1][j+1];
            }else {
                ans = max(dp[i+1][j], dp[i][j+1]);
            }
            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}


int main() {
    string text1 = "abcde";
    string text2 = "ace";

    vector<vector<int>> dp(text1.length() + 1, vector<int> (text2.length() + 1, -1));

    int ansRec = solveRec(text1, text2, 0, 0);
    int ansDp = solveDp(text1, text2, 0, 0, dp);
    int ansTab = solveTab(text1, text2);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using Dp is: " << ansDp << endl;
    cout << "Answer using Tab is: " << ansTab << endl;

    return 0;
}