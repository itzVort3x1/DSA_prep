//------------------------------------
//      House Robber 2
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> nums, int s, int e, vector<int> &dp) {
    if(s > e) {
        return 0;
    } 

    if(dp[s] != -1) {
        return dp[s];
    }

    int include = nums[s] + solve(nums, s + 2, e, dp);
    int exclude = solve(nums, s+1, e, dp);

    dp[s] = max(include, exclude);
    return dp[s];
}

int main() {
    vector<int> nums = {1,2,3,1};

    vector<int> dp1(nums.size() + 1, -1);
    vector<int> dp2(nums.size() + 1, -1);

    int ans1 = solve(nums, 0, nums.size() - 2, dp1);
    int ans2 = solve(nums, 1, nums.size() - 1, dp2);

    cout << "The max is: " << max(ans1, ans2) << endl;

    return 0;
}