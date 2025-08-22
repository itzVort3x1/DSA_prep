//------------------------------------
//      Maximum Subarray
//      Ex: Input : intervals = [-2,1,-3,4,-1,2,1,-5,4];
//          Output : 6
//------------------------------------

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = nums[0];
    int currSum = 0;

    for(int i = 0; i<nums.size(); i++) {
        if(currSum < 0) {
            currSum = 0;
        }

        currSum += nums[i];
        maxSum = max(currSum, maxSum);
    }

    cout << "The max sub array is: " << maxSum << endl;

    return 0;
}