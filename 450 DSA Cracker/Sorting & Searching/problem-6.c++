//------------------------------------
//      Search in Rotated Sorted Array
//      Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    int low = 0;
    int high = nums.size() - 1;

    while(low <= high){
        int mid = high + (high-low)/2;

        if(nums[mid] == target){
            cout << mid << endl;
            return 0;
        }

        if(nums[low] <= nums[mid]){
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    cout << "-1" << endl;

    return 0;
}