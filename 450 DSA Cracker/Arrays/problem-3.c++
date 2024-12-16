//------------------------------------
//      Min and Max in Array
//      Link: https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1
//------------------------------------

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> arr = {3,2,1,56,10000, 167};

    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int num:arr){
        mini = min(mini, num);
        maxi = max(maxi, num);
    }

    cout << "The minimum and the maximum element is: {" << mini << " , " << maxi << "} " << endl;

    return 0;
}