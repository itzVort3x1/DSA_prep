//------------------------------------
//      Maximum sum of Non-Adjacent Elements
//      Ex: INPUT: arr = {9, 9, 8, 2}
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int solveRec(vector<int> &nums, int n){
    if(n < 0){
        return 0;
    }

    if(n==0){
        return nums[0];
    }

    int include = solveRec(nums, n-2) + nums[n];
    int exclude = solveRec(nums, n-1) + 0;

    return max(include, exclude);
}

int solveDp(vector<int> &nums, int n, vector<int> &dp){
    if(n < 0){
        return 0;
    }

    if(n==0){
        return nums[0];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int include = solveDp(nums, n-2, dp) + nums[n];
    int exclude = solveDp(nums, n-1, dp) + 0;

    dp[n] = max(include, exclude);

    return dp[n];
}

int solveTab(vector<int> &nums, int n){
    vector<int> dp(n+1, 0);
    
    dp[0] = nums[0];

    for(int i = 1; i<n; i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }

    return dp[n-1];

}

int solveSpace(vector<int> &nums, int n){
    vector<int> dp(n+1, 0);
    
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i = 1; i<n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        prev2 = prev1;
        prev1 = max(incl, excl);
    }

    return prev1;

}

int main() {
    vector<int> arr = {9,9,8,2};
    int n = arr.size();

    vector<int> dp(n+1, -1);

    int ansRec = solveRec(arr, n);
    int ansDp = solveDp(arr, n, dp);
    int ansTab = solveTab(arr, n);
    int ansSpace = solveSpace(arr, n);

    cout << "Answer using recursion: " << ansRec << endl;
    cout << "Answer using dp: " << ansDp << endl;
    cout << "Answer using tab: " << ansTab << endl;
    cout << "Answer using tab and space optimization: " << ansSpace << endl;

    return 0;
}