//------------------------------------
//      Longest Arithmetic Subsequence of Given Difference
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int d = -2;
    vector<int> arr = {1, 5, 7, 8, 8, 5, 3, 4, 2, 1};

    unordered_map<int, int> dp;

    int ans = 0;

    for(int i = 0; i<arr.size(); i++){
        int temp = arr[i] - d;
        int tempAns = 0;

        if(dp.count(temp)){
            tempAns = dp[temp];
        }

        dp[arr[i]] = 1 + tempAns;

        ans = max(ans, dp[arr[i]]);

    }

    cout << "The answer is: " << ans << endl;

    return 0;

}