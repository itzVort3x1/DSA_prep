//------------------------------------
//      Count Derangements
//      Ex: INPUT: n = 3
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int solveRec(int n){
    if(n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    int ans = (n - 1) * (solveRec(n-1) + solveRec(n-2));

    return ans;
}

int solveMem(int n, vector<long long> &dp){
    if(n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = (n - 1) * (solveMem(n-1, dp) + solveMem(n-2, dp));

    return dp[n];
}

int solveTab(int n){

    vector<long long> dp(n+1, 0);

    dp[1] = 0;
    dp[2] = 1;

    for(int i = 3; i <= n; i++){
        long long int first = dp[i-1];
        long long int second = dp[i-2];
        long long int sum = (first + second);
        long long int ans = (i-1) * sum;
        dp[i] = ans;
    }

    return dp[n];
}

int solveSpace(int n){


    int prev2 = 0;
    int prev1 = 1;

    for(int i = 3; i <= n; i++){
        long long int first = prev1;
        long long int second = prev2;
        long long int sum = (first + second);
        long long int ans = (i-1) * sum;
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main() {
    int n = 5;
    vector<long long> dp(n+1, -1);

    int ansRec = solveRec(n);
    long long ansMem = solveMem(n, dp);
    long long ansTab = solveTab(n);
    long long ansSpace = solveSpace(n);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp mem is: " << ansMem << endl;
    cout << "Answer using Tab is: " << ansTab << endl;
    cout << "Answer using space is: " << ansSpace << endl;

    return 0; 
}