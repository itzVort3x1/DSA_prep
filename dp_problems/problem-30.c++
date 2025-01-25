//------------------------------------
//      Best Time to Buy and Sell Stock-3 (3D DP)
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<int> prices, int buy, int index, int limit){
    if(index == prices.size()){
        return 0;
    }

    if(limit == 0){
        return 0;
    }

    int profit = 0;
    if(buy) {
        profit = max((-prices[index] + solveRec(prices, 0, index+1, limit)), (0 + solveRec(prices, 1, index + 1, limit)));
    }else {
        profit = max((prices[index] + solveRec(prices, 1, index+1, limit-1)), (0 + solveRec(prices, 0, index + 1, limit)));
    }

    return profit;
}

int solveDp(vector<int> prices, int buy, int index, int limit, vector<vector<vector<int>>> &dp){
    if(index == prices.size()){
        return 0;
    }
    if(limit == 0){
        return 0;
    }

    if(dp[index][buy][limit] != -1){
        return dp[index][buy][limit];
    }

    int profit = 0;
    if(buy) {
        profit = max((-prices[index] + solveDp(prices, 0, index+1, limit, dp)), (0 + solveDp(prices, 1, index + 1,limit, dp)));
    }else {
        profit = max((prices[index] + solveDp(prices, 1, index+1, limit-1, dp)), (0 + solveDp(prices, 0, index + 1, limit, dp)));
    }

    return dp[index][buy][limit] = profit;
}

int solveTab(vector<int> prices){
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(3, vector<int>(4,0)));

    int profit = 0;
    for(int i = prices.size() - 1; i >= 0; i--){
        for(int buy=0; buy<=1; buy++){
            for(int limit = 1; limit <= 2; limit++){
                int profit = 0;
                if(buy) {
                    profit = max((-prices[i] + dp[i+1][0][limit]), (0 + dp[i+1][1][limit]));
                }else {
                    profit = max((prices[i] + dp[i+1][1][limit-1]), (0 + dp[i+1][0][limit]));
                }
                dp[i][buy][limit] = profit;
            }
        }
    }

    return dp[0][1][2];
} 

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3,-1)));

    int ansRec = solveRec(prices, 1, 0, 2);
    int ansDp = solveDp(prices, 1, 0, 2, dp);
    int ansTab = solveTab(prices);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp is: " << ansDp << endl;
    cout << "Answer using Tab is: " << ansTab << endl;

    cout << endl;
    return 0;
}