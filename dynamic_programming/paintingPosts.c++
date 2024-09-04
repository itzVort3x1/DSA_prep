//------------------------------------
//      Painting Fence algorithm
//------------------------------------
#include <iostream>
#include <vector>
using namespace std;

int solveUsingRecursion(int n, int k)
{
     if (n == 1)
     {
          return k;
     }

     if (n == 2)
     {
          return k + k * (k - 1);
     }

     int ans = (solveUsingRecursion(n - 1, k) + solveUsingRecursion(n - 2, k)) * (k - 1);
     return ans;
}

int solveUsingMem(int n, int k, vector<int> &dp)
{
     if (n == 1)
     {
          return k;
     }

     if (n == 2)
     {
          return k + k * (k - 1);
     }

     if (dp[n] != -1)
     {
          return dp[n];
     }

     dp[n] = (solveUsingMem(n - 1, k, dp) + solveUsingMem(n - 2, k, dp)) * (k - 1);
     return dp[n];
}

int solveUsingTabulation(int n, int k)
{
     vector<int> dp(n + 1, -1);

     dp[1] = k;
     dp[2] = k + k * (k - 1);

     for (int i = 3; i <= n; i++)
     {
          dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
     }

     return dp[n];
}

long long solveUsingSO(int n, int k)
{
     // vector<int> dp(n + 1, -1);

     long long prev1 = k;
     long long prev2 = k + k * (k - 1);

     long long curr;

     for (int i = 3; i <= n; i++)
     {
          curr = (prev1 + prev2) * (k - 1);
          // shift
          prev2 = prev1;
          prev1 = curr;
     }

     return curr;
}

int main()
{
     int n = 3;
     int k = 3;
     vector<int> dp(n + 1, -1);
     // int ans = solveUsingRecursion(n, k);
     // int ans = solveUsingMem(n, k, dp);
     long long ans = solveUsingSO(n, k);
     cout << "Ans: " << ans << endl;
}