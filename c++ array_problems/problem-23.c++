//------------------------------------
//      Find Pivot index
//      Input: nums = [1,7,3,6,5,6]
//      Output: 3
//      Explanation:
//      The pivot index is 3.
//      Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
//      Right sum = nums[4] + nums[5] = 5 + 6 = 11
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main()
{
     vector<int> nums;

     nums.push_back(1);
     nums.push_back(7);
     nums.push_back(3);
     nums.push_back(6);
     nums.push_back(5);
     nums.push_back(6);
     vector<int> rsum(nums.size(), 0);
     vector<int> lsum(nums.size(), 0);

     for (int i = 1; i < nums.size(); i++)
     {
          lsum[i] = lsum[i - 1] + nums[i - 1];
     }

     for (int i = nums.size() - 2; i >= 0; i--)
     {
          rsum[i] = rsum[i + 1] + nums[i + 1];
     }

     int flag = 0;
     int index = -1;
     for (int i = 0; i < nums.size(); i++)
     {
          if (rsum[i] == lsum[i])
          {
               flag = 1;
               index = i;
               break;
          }
     }

     if (flag)
     {
          cout << "Pivot found at: " << index << endl;
     }
     else
     {
          cout << "Did not find pivot" << endl;
     }
}