//------------------------------------
//      Reducing Dishes
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &satisfaction, int index, int time){
    if(index == satisfaction.size()){
        return 0;
    }

    int include = satisfaction[index] * time + solveRec(satisfaction, index+1, time+1);
    int exclude = solveRec(satisfaction, index+1, time);

    int ans = max(include, exclude);

    return ans;
}

int solveMem(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp){
    if(index == satisfaction.size()){
        return 0;
    }

    if(dp[index][time] != -1){
        return dp[index][time];
    }

    int include = satisfaction[index] * time + solveMem(satisfaction, index+1, time+1, dp);
    int exclude = solveMem(satisfaction, index+1, time, dp);

    dp[index][time] = max(include, exclude);

    return dp[index][time];
}

int solveTab(vector<int> &satisfaction){
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i = n-1; i>=0; i--){
        for(int time = i; time >= 0; time--){
            int include = satisfaction[i] * time + dp[i+1][time+1];
            int exclude = dp[i+1][time];
            dp[i][time] = max(include, exclude);
        }
    }


    return dp[0][0];
}

int solveSpace(vector<int> &satisfaction){
    int n = satisfaction.size();

    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);

    for(int i = n-1; i>=0; i--){
        for(int time = i; time >= 0; time--){
            int include = satisfaction[i] * time + next[time+1];
            int exclude = next[time];
            curr[time] = max(include, exclude);
        }
        next = curr;
    }


    return next[0];
}


int main() {
    vector<int> satisfaction = {-1,-8,0,5,-9};
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n+1, -1));

    sort(satisfaction.begin(), satisfaction.end());

    int ansRec = solveRec(satisfaction, 0, 1);
    int ansMem = solveMem(satisfaction, 0, 1, dp);
    int ansTab = solveTab(satisfaction);
    int ansSpace = solveSpace(satisfaction);


    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using DpMem is: " << ansMem << endl;
    cout << "Answer using tabulation is: " << ansTab << endl;
    cout << "Answer using space optimization is: " << ansSpace << endl;

    return 0;
}