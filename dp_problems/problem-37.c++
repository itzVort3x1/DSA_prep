//------------------------------------
//      Wildcard Pattern Matching
//------------------------------------
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool solveRec(string s, string p, int i, int j){

    if(i < 0 && j < 0){
        return true;
    }

    if(i >= 0 && j < 0){
        return false;
    }

    if(i <= 0 && j >= 0){
        for(int k = 0; k <=j; k++){
            if(p[k] != '*'){
                return false;
            }
        }

        return true;
    }

    if(s[i] == p[j] || p[j] == '?'){
        solveRec(s, p, i-1, j-1);
    }else if(p[j] == '*'){
        return solveRec(s, p, i, j-1) || solveRec(s, p, i-1, j);
    }else {
        return false;
    }

    return false;
}

bool solveDp(string s, string p, int i, int j, vector<vector<int>> &dp){

    if(i < 0 && j < 0){
        return true;
    }

    if(i >= 0 && j < 0){
        return false;
    }

    if(i < 0 && j >= 0){
        for(int k = 0; k <=j; k++){
            if(p[k] != '*'){
                return false;
            }
        }

        return true;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s[i] == p[j] || p[j] == '?'){
        return dp[i][j] = solveRec(s, p, i-1, j-1);
    }else if(p[j] == '*'){
        return dp[i][j] = solveRec(s, p, i, j-1) || solveRec(s, p, i-1, j);
    }else {
        return false;
    }
}

bool solveTab(string s, string p){
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, false));

    dp[0][0] = true;

    for(int j = 1; j <=p.length(); j++){
        bool flag = true;
        for(int k = 1; k <=j; k++){
            if(p[k-1] != '*'){
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for(int i = 1; i<=s.length(); i++){
        for(int j =1; j<=p.length(); j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }else if(p[j-1] == '*'){
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }else {
                dp[i][j] = false;
            }
        }
    }

    return dp[s.length()][p.length()];
}

int main() {
    string s = "aa";
    string p = "*";

    vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));

    bool ansRec = solveRec(s, p, s.length() - 1, p.length() - 1);
    bool ansDp = solveDp(s, p, s.length() - 1, p.length() - 1, dp);
    bool ansTab = solveTab(s, p);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp is: " << ansDp << endl;
    cout << "Answer using Tab is: " << ansTab << endl;

    return 0;
}