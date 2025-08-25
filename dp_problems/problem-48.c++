//------------------------------------
//      Longest Increasing Subsequence
//------------------------------------

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int solve(int curr, int prev, vector<int> &nums, vector<vector<int> > &dp){
    if(curr >= nums.size()){
        return 0;
    }

    if(dp[curr][prev+1] != -1){
        return dp[curr][prev+1];
    }

    int include = 0;
    if(prev == -1 || nums[curr] > nums[prev]){
        include = 1 + solve(curr + 1, curr, nums, dp);
    }
    int exclude = 0 + solve(curr+ 1, prev, nums, dp);

    dp[curr][prev+1] = max(include, exclude);
    return dp[curr][prev+1];
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};

        int prev = -1;
        int curr = 0;

        vector<vector<int> > dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));

        int ans = solve(curr, prev, nums, dp);
        
        cout << "The longest increasing subsequence is: " << ans << endl;

        return 0;
}