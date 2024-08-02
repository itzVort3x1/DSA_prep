//------------------------------------
//      Sliding window maximum
//      Problem Link: https://leetcode.com/problems/sliding-window-maximum/description/
//------------------------------------

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
     vector<int> ans;
     deque<int> dq;

     // processing first window
     for (int i = 0; i < k; i++)
     {
          int element = nums[i];
          // removing smaller element from queue
          while (!dq.empty() && element > nums[dq.back()])
          {
               dq.pop_back();
          }

          // inserting
          dq.push_back(i);
     }

     // processing the remaining
     for (int i = k; i < nums.size(); i++)
     {
          if (!dq.empty())
          {
               ans.push_back(nums[dq.front()]);
          }

          // Remove element not in window size
          while (!dq.empty() && i - dq.front() >= k)
          {
               dq.pop_front();
          }

          int element = nums[i];
          // removing smaller element from queue
          while (!dq.empty() && element > nums[dq.back()])
          {
               dq.pop_back();
          }

          // inserting
          dq.push_back(i);
     }

     ans.push_back(nums[dq.front()]);

     return ans;
}

int main()
{
     vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
     int k = 3;

     vector<int> ans = maxSlidingWindow(nums, k);

     for (int i = 0; i < ans.size(); i++)
     {
          if (i == ans.size() - 1)
          {
               cout << ans[i];
          }
          else
          {
               cout << ans[i] << " --> ";
          }
     }
}