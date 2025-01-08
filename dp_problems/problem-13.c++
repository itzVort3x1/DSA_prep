//------------------------------------
//      Largest Square area in Matrix
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int solveRec(vector<vector<int>> &mat, int i, int j, int &maxi){
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;
    }

    int right = solveRec(mat, i, j+1, maxi);
    int diagonal = solveRec(mat, i+1, j+1, maxi);
    int down = solveRec(mat, i+1, j, maxi);

    if(mat[i][j] == 1){
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }else {
        return 0;
    }

}

int solveDp(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
    if(i >= mat.size() || j >= mat[0].size()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = solveDp(mat, i, j+1, maxi, dp);
    int diagonal = solveDp(mat, i+1, j+1, maxi, dp);
    int down = solveDp(mat, i+1, j, maxi, dp);

    if(mat[i][j] == 1){
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }else {
        return 0;
    }

}

void solveTab(vector<vector<int>> &mat, int &maxi){

    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> dp(row + 1, vector<int>(col+1, 0));

    for(int i = row-1; i>=0;i--){
        for(int j = col-1; j>=0; j--){
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];

            if(mat[i][j] == 1){
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, dp[i][j]);
            }else {
                dp[i][j] = 0;
            }
        }
    }

    return;

}

int main() {
    vector<vector<int>> mat = {{0, 1, 1, 0, 1}, {1, 1, 0, 1, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}};

    vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));

    int maxi=0;

    int ansRec = solveRec(mat, 0, 0, maxi);
    int ansDp = solveDp(mat, 0, 0, maxi, dp);
    solveTab(mat, maxi);

    cout << "Answer using recursion is: " << maxi << endl;
    cout << "Answer using dp is: " << maxi << endl;
    cout << "Answer using tab is: " << maxi << endl;

    cout << endl;

    return 0;
}