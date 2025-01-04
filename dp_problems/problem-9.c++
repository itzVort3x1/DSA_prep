//------------------------------------
//      KnapSack 0/1
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int solveRec(vector<int> &weight, vector<int> values, int W, int index){
    if(index == 0){
        if(weight[0] <= W){
            return values[0];
        }else {
            return 0;
        }
    }

    int incl = 0;
    if(weight[index] <= W){
        incl = values[index] + solveRec(weight, values, W-weight[index], index-1);
    }

    int excl = solveRec(weight, values, W, index - 1);

    int ans = max(excl, incl);

    return ans;

}

int solveDp(vector<int> &weight, vector<int> values, int W, int index, vector<vector<int>> &dp){
    if(index == 0){
        if(weight[0] <= W){
            return values[0];
        }else {
            return 0;
        }
    }

    if(dp[index][W] != -1){
        return dp[index][W];
    }

    int incl = 0;
    if(weight[index] <= W){
        incl = values[index] + solveDp(weight, values, W-weight[index], index-1, dp);
    }

    int excl = solveDp(weight, values, W, index - 1, dp);

    dp[index][W] = max(excl, incl);

    return dp[index][W];

}

int solveTab(vector<int> &weight, vector<int> values, int W){
    
    vector<vector<int>> dp(weight.size(), vector<int>(W+1, 0));

    for(int w = weight[0]; w<=W; w++){
        if(weight[0] <= W){
            dp[0][w] = values[0];
        }else {
            dp[0][w] = 0;
        }
    }

    for(int index = 1; index<weight.size(); index++){
        for(int w = 0; w<=W; w++){
            int incl = 0;
            if(weight[index] <= w){
                incl = values[index] + dp[index - 1][w-weight[index]];
            }

            int excl = 0 + dp[index - 1][w];

            dp[index][w] = max(incl, excl);
        }
    }

    return dp[weight.size()-1][W];

}

int main() {
    vector<int> weight = {1,2,4,5};
    vector<int> values = {5,4,8,6};
    int total =  5; 

    vector<vector<int>> dp(weight.size(), vector<int>(total+1, -1));

    int ansRec = solveRec(weight, values, total, weight.size() - 1);
    int ansDp = solveDp(weight, values, total, weight.size() - 1, dp);
    int ansTab = solveTab(weight, values, total);

    cout << "Answer using recursion is: " << ansRec << endl;
    cout << "Answer using dp is: " << ansDp << endl;
    cout << "Answer using Tab is: " << ansTab << endl;

    return 0;
}