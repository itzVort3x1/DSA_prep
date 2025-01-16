//------------------------------------
//      Dice throw
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveRec(int dice, int faces, int target){
    if(target < 0){
        return 0;
    }

    if(dice == 0 && target != 0){
        return 0;
    }

    if(target == 0 && dice != 0){
        return 0;
    }

    if(dice == 0 && target == 0){
        return 1;
    }

    int ans = 0;
    for(int i = 1; i<=faces; i++){
        ans = ans + solveRec(dice - 1, faces, target - i);
    }

    return ans;
}

int solveDp(int dice, int faces, int target, vector<vector<int>> &dp){
    if(target < 0){
        return 0;
    }

    if(dice == 0 && target != 0){
        return 0;
    }

    if(target == 0 && dice != 0){
        return 0;
    }

    if(dice == 0 && target == 0){
        return 1;
    }

    if(dp[dice][target] != -1){
        return dp[dice][target];
    }

    int ans = 0;
    for(int i = 1; i<=faces; i++){
        ans  = ans + solveDp(dice - 1, faces, target - i, dp);
    }

    return dp[dice][target] = ans;
}

int solveTab(int d, int f, int t){
    vector<vector<int>> dp(d + 1, vector<int> (t + 1, 0));
    
    dp[0][0] = 1;

    for(int dice = 1; dice<=d; dice++){
        for(int target = 1; target <= t; target++){
            int ans = 0;
            for(int i = 1; i<=f; i++){
                if(target - i >= 0){
                    ans  = ans + dp[dice-1][target-i];
                }
            }

            dp[dice][target] = ans;
        }
    }

    return dp[d][t];

}

int main() {
    int n = 3;
    int m = 6;
    int x = 12;

    vector<vector<int>> dp(n+1, vector<int> (x + 1, -1));

    int ansRec = solveRec(n, m, x);
    int ansDp = solveDp(n, m, x, dp);
    int ansTab = solveTab(n, m, x);

    cout << "Answer using rec: " << ansRec << endl;
    cout << "Answer using dp: " << ansDp << endl;
    cout << "Answer using Tab: " << ansTab << endl;

    return 0;
}