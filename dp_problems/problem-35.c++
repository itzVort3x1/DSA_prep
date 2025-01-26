//------------------------------------
//      EDIT Distance
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveRec(string &a, string &b, int i, int j){
    if(a.length() == i){
        return b.length() - j;
    }

    if(j == b.length()) {
        return a.length() - i;
    }

    int ans = 0;
    if(a[i] == b[j]){
        ans = solveRec(a, b, i+1, j+1);
    }else {
        //insert
        int insertAns = 1 + solveRec(a,b,i,j+1);

        //delete
        int deleteAns = 1 + solveRec(a,b,i+1,j);

        //replace
        int replaceAns = 1 + solveRec(a,b,i+1,j+1);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }

    return ans;
}

int solveDp(string &a, string &b, int i, int j, vector<vector<int>> &dp){
    if(a.length() == i){
        return b.length() - j;
    }

    if(j == b.length()) {
        return a.length() - i;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 0;
    if(a[i] == b[j]){
        ans = solveDp(a, b, i+1, j+1, dp);
    }else {
        //insert
        int insertAns = 1 + solveDp(a,b,i,j+1, dp);

        //delete
        int deleteAns = 1 + solveDp(a,b,i+1,j, dp);

        //replace
        int replaceAns = 1 + solveDp(a,b,i+1,j+1, dp);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }

    return dp[i][j] = ans;
}

int solveTab(string &a, string &b){
    vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
    
    for(int j=0; j<b.length(); j++){
        dp[a.length()][j] = b.length() - j;
    }

    for(int i=0; i<a.length(); i++){
        dp[i][b.length()] = a.length() - i;
    }

    for(int i = a.length() - 1; i>=0; i--){
        for(int j = b.length() - 1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j]){
                ans = dp[i+1][j+1];
            }else {
                //insert
                int insertAns = 1 + dp[i][j+1];

                //delete
                int deleteAns = 1 + dp[i+1][j];

                //replace
                int replaceAns = 1 + dp[i+1][j+1];

                ans = min(insertAns, min(deleteAns, replaceAns));
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][0];

}

int main() {
    string word1 = "horse";
    string word2 = "ros";

    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));

    int ansRec = solveRec(word1, word2, 0, 0);
    int ansDp = solveDp(word1, word2, 0, 0, dp);
    int ansTab = solveTab(word1, word2);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp is: " << ansDp << endl;
    cout << "Answer using Tab is: " << ansTab << endl;

    return 0;
}