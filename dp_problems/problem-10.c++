//------------------------------------
//      Combination Sum IV Problem
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int solveRec(vector<int> arr, int target){
    if(target == 0){
        return 1;
    }

    if(target < 0){
        return 0;
    }

    int ans = 0;
    for(int i = 0; i<arr.size(); i++){
        ans += solveRec(arr, target - arr[i]);
    }

    return ans;

}

int solveDp(vector<int> arr, int target, vector<int> &dp){
    if(target == 0){
        return 1;
    }

    if(target < 0){
        return 0;
    }

    if(dp[target] != -1){
        return dp[target];
    }

    for(int i = 0; i<arr.size(); i++){
        dp[target] += solveRec(arr, target - arr[i]);
    }

    return dp[target];

}

int solveTab(vector<int> arr, int target){
    vector<int> dp(target+1, 0);

    dp[0] = 1;

    for(int i = 1; i <= target; i++){
        for(int j=0; j<arr.size(); j++){
            if(i-arr[j] >=  0){
                dp[i] += dp[i - arr[j]];
            }
        }
    }

    return dp[target];

}

int main() {
    vector<int> arr = {1,2, 5};
    int target = 5;

    vector<int> dp(target + 1, -1);

    int ansRec = solveRec(arr, target);
    int ansDp = solveDp(arr, target, dp);
    int ansTab = solveTab(arr, target);

    cout << "Answer using recursion: " << ansRec << endl;
    cout << "Answer using dp: " << ansRec << endl;
    cout << "Answer using tab: " << ansTab << endl;

    return 0;
}
