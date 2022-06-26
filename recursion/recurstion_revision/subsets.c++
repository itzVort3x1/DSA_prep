#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> arr, vector<int> output, int index, vector<vector<int> > &ans)
{
     // base case
     if (index >= arr.size())
     {
          ans.push_back(output);
          return;
     }

     // exclude
     solve(arr, output, index + 1, ans);

     // include
     int element = arr[index];
     output.push_back(element);
     solve(arr, output, index + 1, ans);
}

int main()
{
     vector<int> arr = {1, 2, 3};

     vector<vector<int> > ans;
     vector<int> output;
     int index = 0;

     solve(arr, output, index, ans);

     for (int i = 0; i < ans.size(); i++)
     {
          for (int j = 0; j < ans[i].size(); j++)
          {
               cout << ans[i][j] << " ";
          }
          cout << endl;
     }
}