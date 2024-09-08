#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int capacity, int wt[], int profit[], int index, int n)
{
     // base case
     if (index >= n)
     {
          return 0;
     }

     // include / exclude
     int include = 0;
     if (wt[index] <= capacity)
     {
          include = profit[index] + solveUsingRecursion(capacity - wt[index], wt, profit, index + 1, n);
     }
     int exclude = 0 + solveUsingRecursion(capacity, wt, profit, index + 1, n);

     int ans = max(include, exclude);

     return ans;
}

int solveUsingMem(int capacity, int wt[], int profit[], int index, int n, vector<vector<int> > &dp)
{
     // base case
     if (index >= n)
     {
          return 0;
     }

     if (dp[capacity][index] != -1)
     {
          return dp[capacity][index];
     }

     // include / exclude
     int include = 0;
     if (wt[index] <= capacity)
     {
          include = profit[index] + solveUsingMem(capacity - wt[index], wt, profit, index + 1, n, dp);
     }
     int exclude = 0 + solveUsingMem(capacity, wt, profit, index + 1, n, dp);

     dp[capacity][index] = max(include, exclude);

     return dp[capacity][index];
}

int solveUsingTabulation(int capacity, int wt[], int profit, int index, int n){
     vector<vector<int> > dp(capacity + 1, vector<int>(n + 1, -1));

     
}

int main()
{
     int capacity = 50;
     int wt[] = {10, 20, 30};
     int profit[] = {60, 100, 120};
     int index = 0;
     int n = 3;

     vector<vector<int> > dp(capacity + 1, vector<int>(n + 1, -1));

     // int ans = solveUsingRecursion(capacity, wt, profit, index, n);
     int ans = solveUsingMem(capacity, wt, profit, index, n, dp);

     cout << "Ans: " << ans << endl;

     return 0;
}