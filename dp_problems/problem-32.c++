//------------------------------------
//      Best Time to Buy and Sell Stock with Transaction Fee
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveTab(vector<int> prices, int fee){
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

    int profit = 0;
    for(int i = prices.size() - 1; i >= 0; i--){
        for(int buy=0; buy<=1; buy++){

            int profit = 0;
            if(buy) {
                profit = max((-prices[i] + dp[i+1][0]), (0 + dp[i+1][1]));
            }else {
                profit = max((prices[i] + dp[i+1][1] - fee), (0 + dp[i+1][0]));
            }
            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
} 

int main() {
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;

    int ansTab = solveTab(prices, fee);

    cout << "Answer using Tabulation is: " << ansTab << endl;

    return 0;
}