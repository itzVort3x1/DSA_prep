//------------------------------------
//      Minimum Sideways Jump
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> obstacles, int currlane, int currpos){

    int n = obstacles.size() - 1;

    if(currpos == n){
        return 0;
    }

    if(obstacles[currpos+1] != currlane){
        return solveRec(obstacles, currlane, currpos + 1);
    }else {
        int ans = INT_MAX;
        for(int i = 1; i<=3; i++){
            if(currlane != i && obstacles[currpos] != i){
                ans = min(ans, 1 + solveRec(obstacles, i, currpos));
            }
        }

        return ans;
    }
}

int solveDp(vector<int> obstacles, int currlane, int currpos){

    int n = obstacles.size() - 1;

    if(currpos == n){
        return 0;
    }

    if(obstacles[currpos+1] != currlane){
        return solveRec(obstacles, currlane, currpos + 1);
    }else {
        int ans = INT_MAX;
        for(int i = 1; i<=3; i++){
            if(currlane != i && obstacles[currpos] != i){
                ans = min(ans, 1 + solveDp(obstacles, i, currpos));
            }
        }

        return ans;
    }
}

int solveDp(vector<int> obstacles, int currlane, int currpos, vector<vector<int>> &dp){

    int n = obstacles.size() - 1;

    if(currpos == n){
        return 0;
    }

    if(dp[currlane][currpos] != -1){
        return dp[currlane][currpos];
    }

    if(obstacles[currpos+1] != currlane){
        return solveDp(obstacles, currlane, currpos + 1, dp);
    }else {
        int ans = INT_MAX;
        for(int i = 1; i<=3; i++){
            if(currlane != i && obstacles[currpos] != i){
                ans = min(ans, 1 + solveDp(obstacles, i, currpos));
            }
        }

        dp[currlane][currpos] = ans;
    }

    return dp[currlane][currpos];
}

int solveTab(vector<int> obstacles){

    int n = obstacles.size() -1;

    vector<vector<int>> dp(4, vector<int> (obstacles.size(), 1e9));
    
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for(int currpos = n - 1; currpos >= 0; currpos--){
        for(int currlane = 1; currlane<=3; currlane++){
            if(obstacles[currpos+1] != currlane){
                dp[currlane][currpos] = dp[currlane][currpos+1];
            }else {
                int ans = 1e9;
                for(int i = 1; i<=3; i++){
                    if(currlane != i && obstacles[currpos] != i){
                        ans = min(ans, 1 + dp[i][currpos]);
                    }
                }

                dp[currlane][currpos] = ans;
            }
        }
    }

    return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));

}

int main() {
    vector<int> obstacles = {0,1,2,3,0};

    vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));

    int ansRec = solveRec(obstacles, 2, 0);
    int ansDp = solveDp(obstacles, 2, 0,dp);
    int ansTab = solveTab(obstacles);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp is: " << ansDp << endl;
    cout << "Answer using tab is: " << ansTab << endl;

    cout << endl;
}