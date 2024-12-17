//------------------------------------
//      Kadane's Algorithm
//      Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
//------------------------------------

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> arr = {2,3,-8,7,-1,2,3};

    int sum = 0;
    int ans = INT_MIN;

    for(int num: arr){
        sum += num;

        ans = max(sum, ans);

        if(sum < 0){
            sum = 0;
        }
    }

    cout << "The maximum value is: " << ans << endl;

    return 0;
}