//------------------------------------
//      Minimum Cost Climbing Stairs
//      Ex: INPUT: n = 10
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

// N Distinct ways to reach the nth stairs
int nDistWays(int n, int i){
    if(n == i){
        return 1;
    }

    if(i > n){
        return 0;
    }

    int cost = nDistWays(n, i+ 1) + nDistWays(n, i+2);

    return cost;
}


// Min cost using recursion
int minCost(vector<int> &cost, int n){
    if(n == 0){
        return cost[0];
    }

    if(n == 1){
        return cost[1];
    }

    int ans = cost[n] + min(minCost(cost, n - 1), minCost(cost, n-2));
    return ans;
}

// Min cost using DP top down approach
int minCostDPTop(vector<int> &cost, int n, vector<int> &dp){
    if(n == 0){
        return cost[0];
    }

    if(n == 1){
        return cost[1];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = cost[n] + min(minCost(cost, n - 1), minCost(cost, n-2));
    return dp[n];
}

// Min cost using DP bottom up approach
int minCostDPBottom(vector<int> &cost, int n){
    vector<int> dp(n+1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i<n; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}

// Min cost using DP bottom up approach
int minCostDPSpace(vector<int> &cost, int n){
    vector<int> dp(n+1);
    int prev2 = cost[0];
    int prev1 = cost[1];

    for(int i = 2; i<n; i++){
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev2, prev1);
}

int main() {
    int n = 3;
    vector<int> cost = {10,15,20};
    vector<int> dp(n+1, -1);

    int res= nDistWays(n, 0);

    int ans = minCost(cost, n);

    int ans2 = minCostDPTop(cost, n, dp);

    int ans3 = minCostDPBottom(cost, n);

    int ans4 = minCostDPSpace(cost, n);

    cout << "The answer using recursion: " << res << endl;
    cout << "The answer of min cost is: " << ans << endl;
    cout << "The answer of min cost using dp Top down approach is: " << ans2 << endl;
    cout << "The answer of min cost using dp bottom top approach is: " << ans3 << endl;
    cout << "The answer of min cost using dp bottom top approach with space optimization is: " << ans4 << endl;

    return 0;

}