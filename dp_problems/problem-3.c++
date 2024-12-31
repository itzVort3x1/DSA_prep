//------------------------------------
//      Minimum Number of Coins
//      Ex: INPUT: n = 10
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int solveRec(vector<int> coins, int target){
    if(target == 0){
        return 0;
    }

    if(target < 0){
        return INT_MAX;
    }

    int mini = INT_MAX;

    for(int i = 0; i<coins.size(); i++){
        int ans = solveRec(coins, target-coins[i]);
        if(ans != INT_MAX){
            mini = min(mini, 1 + ans);
        }
    }

    return mini;
}

int solveDp(vector<int> coins, int target, vector<int> &dp){

    if(target == 0){
        return 0;
    }

    if(dp[target] != -1){
        return dp[target];
    }

    int mini = INT_MAX;

    for(int i = 0; i<coins.size(); i++){
        if(target - coins[i] >= 0){
            int ans = solveDp(coins, target-coins[i], dp);
            if(ans != INT_MAX){
                dp[target] = min(mini, 1 + ans);
            }
        }
    }

    return dp[target];
}

int solveTab(vector<int> coins, int target){

    vector<int> dp(target + 1, INT_MAX);

    dp[0] = 0;

    for(int i = 1; i<=target; i++){
        for(int j = 0; j<coins.size(); j++){
            if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i-coins[j]]);
            }
        }
    }

    if(dp[target] == INT_MAX){
        return -1;
    }
    
    return dp[target];
}


int main() {
    vector<int> coins = {1,2,3};
    int target = 7;

    vector<int> dp(target+1, -1);

    int ansRec = solveRec(coins, target);
    int ansDp = solveDp(coins, target, dp);
    int ansTab = solveTab(coins, target);

    cout << "The minimum number of coins required using recursion is: " << ansRec << endl;
    cout << "The minimum number of coins required using dp is: " << ansDp << endl;
    cout << "The minimum number of coins required using dp Tabulation is: " << ansTab << endl;

    return 0;
}