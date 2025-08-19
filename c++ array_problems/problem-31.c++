//------------------------------------
//      Number of Zero-Filled Subarrays
//      Ex: Input : nums = [1,3,0,0,2,0,0,4]
//          Output :  6
//------------------------------------

#include <iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {1,3,0,0,2,0,0,4};

    int total_sub = 0;
    int consecutive_sub = 0;

    for(int num: nums) {
        if(num == 0) {
            consecutive_sub += 1;
            total_sub += consecutive_sub;
        }else {
            consecutive_sub = 0;
        }
    }

    cout << "The total number of consecutive subarrays are: " << total_sub << endl;

}