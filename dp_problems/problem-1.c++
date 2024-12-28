//------------------------------------
//      Fibbonaci series
//      Ex: INPUT: n = 10
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

// recursive - top down approach
int nthFib(int n, vector<int> &dp){
    if(n <= 1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }


    dp[n] = nthFib(n-1, dp) + nthFib(n-2, dp);

    return dp[n];
}

// Iterative approach bottom top
int nthFibTab(int n){
    vector<int> dp(n+1,-1);

    dp[1] = 1;
    dp[0] = 0;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// Iterative approach bottom top (space optimization)
int nthFibTabSpace(int n){
    int prev1 = 1;
    int prev2 = 0;

    for(int i=2; i<=n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n = 10;

    vector<int> dp(n+1, -1);
    int res = nthFib(n, dp);
    int res2 = nthFibTab(n);
    int res3 = nthFibTabSpace(n);

    cout << "The nth fib is: " << res << endl << "Answer with tabulation method: " << res2 << endl << "Answer with space optimization: " << res3 << endl;

    return 0;

}