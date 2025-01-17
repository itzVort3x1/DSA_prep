//------------------------------------
//      Partition Equal Subset Sum
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool solveRec(vector<int> arr, int target, int index){
    if(index >= arr.size()){
    return false;
    }

    if(target < 0){
    return false;
    }

    if(target == 0){
    return true;
    }

    bool incl = solveRec(arr, target - arr[index], index+1);
    bool excl = solveRec(arr, target, index+1);

    return incl || excl;
};

bool solveDp(vector<int> arr, int target, int index, vector<vector<int>> &dp){
    if(index >= arr.size()){
        return false;
    }

    if(target < 0){
        return false;
    }

    if(target == 0){
        return true;
    }

    if(dp[index][target] != -1){
        return dp[index][target];
    }

    bool incl = solveDp(arr, target - arr[index], index+1, dp);
    bool excl = solveDp(arr, target, index+1, dp);

    dp[index][target] = incl || excl;

    return dp[index][target];
};

bool solveTab(vector<int> arr, int total){
    vector<vector<int>> dp(arr.size() +1, vector<int>(total + 1, 0));

    for(int i = 0; i<=arr.size(); i++){
        dp[i][0] = 1;
    }

    for(int index = arr.size() - 1; index >= 0; index--){
        for(int target = 0; target <= total; target++){
            bool incl = 0;
            if(target - arr[index] >= 0){
                incl = dp[index+1][target-arr[index]];
            }
            bool excl = dp[index+1][target];

            dp[index][target] = incl || excl;
        }
    }

    return dp[0][total];

};


int main() {
    vector<int> arr = {1,5,11,5};

    int sum = 0;
    for(int n:arr) sum+=n;

    if(sum & 1){
        cout << "Not possible." << endl;
        return 0;
    }

    vector<vector<int>> dp(arr.size() + 1, vector<int>(sum/2+1, -1));

    bool ansRec = solveRec(arr, sum/2, 0);
    bool ansDp = solveDp(arr, sum/2, 0, dp);
    bool ansTab = solveTab(arr, sum/2);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp is: " << ansDp << endl;
    cout << "Answer using Tab is: " << ansTab << endl;

    return 0;
}