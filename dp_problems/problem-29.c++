//------------------------------------
//      Best Time to Buy and Sell Stock-2
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<int> prices, int buy, int index){
    if(index == prices.size()){
        return 0;
    }

    int profit = 0;
    if(buy) {
        profit = max((-prices[index] + solveRec(prices, 0, index+1)), (0 + solveRec(prices, 1, index + 1)));
    }else {
        profit = max((prices[index] + solveRec(prices, 1, index+1)), (0 + solveRec(prices, 0, index + 1)));
    }

    return profit;
}   

int solveDp(vector<int> prices, int buy, int index, vector<vector<int>> &dp){
    if(index == prices.size()){
        return 0;
    }

    if(dp[index][buy] != -1){
        return dp[index][buy];
    }

    int profit = 0;
    if(buy) {
        profit = max((-prices[index] + solveDp(prices, 0, index+1, dp)), (0 + solveDp(prices, 1, index + 1, dp)));
    }else {
        profit = max((prices[index] + solveDp(prices, 1, index+1, dp)), (0 + solveDp(prices, 0, index + 1, dp)));
    }

    return dp[index][buy] = profit;
} 

int solveTab(vector<int> prices){
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

    int profit = 0;
    for(int i = prices.size() - 1; i >= 0; i--){
        for(int buy=0; buy<=1; buy++){

            int profit = 0;
            if(buy) {
                profit = max((-prices[i] + dp[i+1][0]), (0 + dp[i+1][1]));
            }else {
                profit = max((prices[i] + dp[i+1][1]), (0 + dp[i+1][0]));
            }
            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
} 

int main() {

    vector<int> prices = {7,1,5,3,6,4};
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));

    int ansRec = solveRec(prices, 1, 0);
    int ansDp = solveDp(prices, 1, 0, dp);
    int ansTab = solveTab(prices);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp is: " << ansDp << endl;
    cout << "Answer using Tab is: " << ansTab << endl;

    cout << endl;
    return 0;
}