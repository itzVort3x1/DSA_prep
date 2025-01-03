//------------------------------------
//      Painting Fence Algorithm
//      Ex: INPUT: n = 3, k = 2
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return ((a%MOD) * (b%MOD))%MOD;
}

int solveRec(int n, int k){
    if(n == 1){
        return k;
    }

    if(n == 2){
        return add(k, mul(k, k-1));
    }

    int ans = add(mul(solveRec(n-2, k), k-1), mul(solveRec(n-1, k), k-1));

    return ans;
}

int solveDp(int n, int k, vector<int> &dp){
    if(n == 1){
        return k;
    }

    if(n == 2){
        return add(k, mul(k, k-1));
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = add(mul(solveDp(n-2, k, dp), k-1), mul(solveDp(n-1, k, dp), k-1));

    return dp[n];
}

int solveTab(int n, int k){
    vector<int> dp(n+1, -1);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));

    for(int i = 3; i<=n; i++){
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }

    return dp[n];
}

int solveSpace(int n, int k){
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));

    for(int i = 3; i<=n; i++){
        int ans = add(mul(prev2, k-1), mul(prev1, k-1));
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main() {
    // n posts and k colours
    // Condition: Not more than two adjacent posts has same color.
    int n = 3;
    int k = 2;
    vector<int> dp(n+1, -1);

    int ansRec = solveRec(n, k);
    int ansDp = solveDp(n, k, dp);
    int ansTab = solveTab(n, k);
    int ansSpace = solveSpace(n, k);

    cout << "Answer using Rec is: " << ansRec << endl;
    cout << "Answer using dp is: " << ansDp << endl;
    cout << "Answer using tab is: " << ansTab << endl;
    cout << "Answer using space is: " << ansSpace << endl;

    return 0;

}