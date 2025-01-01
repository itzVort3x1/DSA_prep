//------------------------------------
//      House Robbery Problem
//      Ex: INPUT: arr = {1,2,3,1}
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int solveRec(vector<int> arr, int n){
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return arr[n];
    }

    int incl = solveRec(arr, n-2) + arr[n];
    int excl = solveRec(arr, n-1) + 0;

    return max(incl, excl);
}

int solveDp(vector<int> arr, int n, vector<int> dp){
    if(n < 0){
        return 0;
    }

    if(n == 0){
        return arr[n];
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int incl = solveRec(arr, n-2) + arr[n];
    int excl = solveRec(arr, n-1) + 0;

    dp[n] = max(incl, excl);

    return dp[n];
}

int solveTab(vector<int> arr, int n){
    vector<int> dp(n+1, 0);

    dp[0] = arr[0];

    for(int i = 1; i<n; i++){
        int incl = dp[i-2] + arr[i];
        int excl = dp[i-1] + 0;
        dp[n] = max(incl, excl);
    }

    return dp[n];

}

int solveSpace(vector<int> arr, int n){
    int prev2 = 0;
    int prev1 = arr[0];

    for(int i = 1; i<n; i++){
        int incl = prev2 + arr[i];
        int excl = prev1 + 0;
        prev2 = prev1;
        prev1 = max(incl, excl);
    }

    return prev1;

}


int main() {
    vector<int> arr = {1,2,3,1};
    int n = arr.size();

    vector<int> dp(n+1, -1);

    if(n == 1){
        cout << arr[0] << endl;
        return 0;
    }

    vector<int> first, second;

    for(int i = 0; i<n; i++){
        if(i!=n-1){
            first.push_back(arr[i]);
        }
        if(i!=0){
            second.push_back(arr[i]);
        }
    }

    int ansRec = max(solveRec(first, first.size()), solveRec(second, second.size()));
    int ansDp = max(solveDp(first, first.size(), dp), solveDp(second, second.size(), dp));
    int ansTab = max(solveTab(first, first.size()), solveTab(second, second.size()));
    int ansSpace = max(solveSpace(first, first.size()), solveSpace(second, second.size()));

    cout << "Answer using recursion: " << ansRec << endl;
    cout << "Answer using dp: " << ansDp << endl;
    cout << "Answer using tab: " << ansTab << endl;
    cout << "Answer using tab and space optimization: " << ansSpace << endl;

    return 0;
}