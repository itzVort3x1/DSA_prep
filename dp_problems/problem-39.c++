//------------------------------------
//      Climbing Stairs
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int solve(int n, int index, vector<int> &dp) {
    if(index == 0) {
        return 1;
    }

    if(index < 0) {
        return 0;
    }

    if(dp[index] != -1) {
        return dp[index];
    }

    dp[index] = solve(n, index-1, dp) + solve(n, index-2, dp);
    return dp[index];
}

int main() {
    int n = 2;

    vector<int>dp(n+1, -1);

    int ans = solve(n, n, dp);

    cout << ans << endl;

    return 0;

}