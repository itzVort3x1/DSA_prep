//------------------------------------
//      EKO-SPOJ
//      Ex: INPUT: arr = {20,15,10,17}, M = 7, N = 4
//          OUTPUT: 15
//          LINK: https://www.spoj.com/problems/EKO/
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<long long int> trees, long long int m, long long int mid)
{
     long long int sum = 0;
     for (int i = 0; i < trees.size(); i++)
     {
          if (trees[i] > mid)
          {
               sum += trees[i] - mid;
          }
     }

     return sum >= m;
}

long long int maxSawBladeHeight(vector<long long int> trees, long long int m)
{
     long long int start = 0, end, ans = -1;

     end = *max_element(trees.begin(), trees.end());

     while (start <= end)
     {
          long long int mid = start + (end - start) / 2;
          if (isPossibleSolution(trees, m, mid))
          {
               ans = mid;
               start = mid + 1;
          }
          else
          {
               end = mid - 1;
          }
     }

     return ans;
}

int main()
{
     long long int n, m;
     cin >> n >> m;

     vector<long long int> trees;

     while (n--)
     {
          long long int height;
          cin >> height;
          trees.push_back(height);
     }

     cout << "Answer is: " << maxSawBladeHeight(trees, m) << endl;
}