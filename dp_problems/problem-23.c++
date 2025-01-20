//------------------------------------
//      Partition Equal Subset Sum
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int solve(int index, int diff, vector<int> arr, unordered_map<int, int> dp[]){
    if(index < 0) { 
        return 0;
    }

    if(dp[index].count(diff)){
        return dp[index][diff];
    }

    int ans = 0;
    for(int j = index - 1; j >=0; j--){
        if(arr[index] - arr[j] == diff){
            ans = max(ans, 1 + solve(j, diff, arr, dp));
        }
    }

    return dp[index][diff] = ans;
}


int main() {
    vector<int> arr = {1,7,10,13,14,19};

    int n = arr.size();

    if (n <= 2){
        cout << "The answer is: " << n << endl;
        return 0;
    }

    unordered_map<int, int> dp[n+1];
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j < n; j++){
            ans = max(ans, 2 + solve(i, arr[j] - arr[i], arr, dp));
        }
    }

    cout << "Answer using recursion: " << ans << endl;

    return 0;
}