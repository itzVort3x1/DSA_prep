//------------------------------------
//      Coin Change
//------------------------------------

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(vector<int> coins, int amount, vector<int> &dp) {
    if(amount == 0) {
        return 0;
    }

    if(dp[amount] != -1) {
        return dp[amount];
    }

    int mini = INT_MAX;

    for(int i = 0; i < coins.size(); i++) {
        if(amount-coins[i] >= 0) {
            int ans = solve(coins, amount - coins[i], dp);
            if(ans != INT_MAX) {
                mini = min(mini, 1 + ans);
            }
        }
    }

    dp[amount] = mini;
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    vector<int> dp(amount + 1, -1);

    int ans = solve(coins, amount, dp);

    if(ans == INT_MAX) {
        return -1;
    }

    cout << "The minimum number of coins required are: " << ans << endl;

    return 0;

}