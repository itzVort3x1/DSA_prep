//------------------------------------
//      House Robber
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> nums, int index, vector<int> &dp) {
    if(index >= nums.size()) {
        return 0;
    }

    if(dp[index] != -1) {
        return dp[index];
    }

    int include = nums[index] + solve(nums, index + 2, dp);
    int exclude = solve(nums, index+1, dp);

    dp[index] = max(include, exclude);
    return dp[index];
}

int main() {
    vector<int> nums = {2,7,9,3,1};

    vector<int> dp(nums.size() + 1, -1);

    int ans = solve(nums, 0, dp);

    cout << "The maximum is: " << ans << endl;

    return 0;
}