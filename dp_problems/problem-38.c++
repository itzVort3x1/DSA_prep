//------------------------------------
//      knapsack 0/1
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int W){
    if(index == 0){
        if(weight[0] <= W){
            return value[0];
        }else {
            return 0;
        }
    }

    int include = 0;
    if(weight[index] <= W){
        include = value[index] + solve(weight, value, index-1, W-weight[index]);
    }

    int exclude = 0 + solve(weight, value, index-1, W);

    int ans = max(include, exclude);

    return ans;

}

int solveMem(vector<int> &weight, vector<int> &value, int index, int W, vector<vector<int>> &dp){
    if(index == 0){
        if(weight[0] <= W){
            return value[0];
        }else {
            return 0;
        }
    }

    if(dp[index][W] != -1){
        return dp[index][W];
    }

    int include = 0;
    if(weight[index] <= W){
        include = value[index] + solve(weight, value, index-1, W-weight[index]);
    }

    int exclude = 0 + solve(weight, value, index-1, W);

    dp[index][W] = max(include, exclude);

    return dp[index][W];

}

int main() {
    vector<int> weight = {5,4,2,3};
    vector<int> value = {10,40,30,50};
    int maxWeight = 5;
    vector<vector<int>> dp(weight.size(), vector<int>(maxWeight+1, -1));

     int n =4;

    int ans = solve(weight, value, n-1, maxWeight);

    int ansMem = solveMem(weight, value, n-1, maxWeight, dp);

    cout << "Recursion Ans: " << ans << endl;

    cout << "Memoization Ans: " << ansMem << endl;

}