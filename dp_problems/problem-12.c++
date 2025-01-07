//------------------------------------
//      Minimum Cost for Tickets
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solveRec(int n, vector<int> &days, vector<int> &cost, int index){
    // BASE CASE
    if(index >= n){
        return 0;
    }

    int option1 = cost[0] + solveRec(n, days, cost, index+1);
    
    int i;
    for(int i = index; i < n && days[i] < days[index] + 7; i++);
    int option2 = cost[1] + solveRec(n, days, cost, i);

    for(int i=index; i<n && days[i] < days[index] + 30; i++);
    int option3 = cost[2] + solveRec(n, days, cost, i);

    return min(option1, min(option2, option3));

}

int solveDp(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp){
    // BASE CASE
    if(index >= n){
        return 0;
    }

    if(dp[index] != -1){
        return -1;
    }

    int option1 = cost[0] + solveDp(n, days, cost, index+1, dp);
    
    int i;
    for(int i = index; i < n && days[i] < days[index] + 7; i++);
    int option2 = cost[1] + solveDp(n, days, cost, i, dp);

    for(int i=index; i<n && days[i] < days[index] + 30; i++);
    int option3 = cost[2] + solveDp(n, days, cost, i, dp);

    dp[index] = min(option1, min(option2, option3));

    return dp[index];

}

int solveTab(int n, vector<int> &days, vector<int> &cost){
    // BASE CASE
    vector<int> dp(n+1, INT_MAX);

    dp[n] = 0;

    for(int k = n -1; k >= 0; k--){
        int option1 = cost[0] + dp[k+1];
    
        int i;
        for(int i = k; i < n && days[i] < days[k] + 7; i++);
        int option2 = cost[1] + dp[i];

        for(int i=k; i<n && days[i] < days[k] + 30; i++);
        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }

    return dp[0];


}

int main() {
    vector<int> days = {1,4,6,7,8,20};
    vector<int> cost = {2,7,15};

    int n = days.size();
    vector<int> dp(n+1, -1);

    int ansRec = solveRec(n, days, cost, 0);
    int ansDp = solveDp(n, days, cost, 0, dp);
    int ansTab = solveTab(n, days, cost);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp is: " << ansDp << endl;
    cout << "Answer using tab is: " << ansTab << endl;

    return 0;

}