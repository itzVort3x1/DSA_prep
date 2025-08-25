//------------------------------------
//      Maimum Product Subarray
//------------------------------------

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    vector<int> nums = {2,3,-2,4};

    int res = *max_element(nums.begin(), nums.end());

    int currMax = 1, currMin = 1;

    for(int n:nums) {
        int temp = currMax * n;
        currMax = max({temp, currMin *n, n});

        currMin = min({temp, currMin * n, n});

        res = max(res, currMax);
    }

    cout << "The largest product is: " << res;

    return 0;

}