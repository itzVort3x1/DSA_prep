//------------------------------------
//      Minimum Cost Tree From Leaf Values
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right){
    if(left == right){
        return 0;
    }

    int ans = INT_MAX;

    for(int i = left; i < right; i++){
        ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solveRec(arr, maxi, left, i) + solveRec(arr, maxi, i+1, right));
    }

    return ans;
}

int solveMem(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp){
    if(left == right){
        return 0;
    }

    if(dp[left][right] != -1){
        return dp[left][right];
    }

    int ans = INT_MAX;

    for(int i = left; i < right; i++){
        ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solveRec(arr, maxi, left, i) + solveRec(arr, maxi, i+1, right));
    }

    return dp[left][right] = ans;
}

int main () {

    vector<int> arr = {3, 6, 4, 7, 2, 5};

    vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));

    map<pair<int, int>, int> maxi;

    for(int i = 0; i<arr.size(); i++){
        maxi[{i, i}] = arr[i];
        for(int j = i+1; j < arr.size(); j++){
            maxi[{i,j}] = max(arr[j], maxi[{i,j-1}]);
        }
    }

    int ansRec = solveRec(arr, maxi, 0, arr.size()-1);
    int ansMem = solveMem(arr, maxi, 0, arr.size()-1, dp);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using mem is: " << ansMem << endl;

    cout << endl;

    return 0;
}