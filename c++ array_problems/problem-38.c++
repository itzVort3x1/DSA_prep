//------------------------------------
//      Jump Game
//      Ex: Input : intervals = [2,3,1,1,4];
//          Output : true
//------------------------------------

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {2,3,1,1,4};

    int goal = nums.size() - 1;

    for(int i = goal; i >= 0; i--) {
        if(i + nums[i] >= goal) {
            goal = i;
        }
    }

    if(goal == 0) {
        cout << "True" << endl;
    }else {
        cout << "False" << endl;
    }
    
    return 0;
}