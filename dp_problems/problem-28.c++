//------------------------------------
//      Best Time to Buy and Sell Stock
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> prices){
    int mini = prices[0];
    int profit = 0;
    for(int i = 1; i<prices.size(); i++){
        int diff = prices[i] - mini;
        profit = max(profit, diff);
        mini = min(mini, prices[i]);
    }

    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = solve(prices);

    cout << "Answer using recursion is: " << ans << endl;

    cout << endl;

    return 0;

}