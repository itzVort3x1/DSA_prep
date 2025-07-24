//------------------------------------
//      Find the min, max and avg of the elements in a row
//------------------------------------

#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int main() {
    vector<vector<int>> arr = {{1,4,3,2}, {4,2,6,7,2}, {3,4,6,8,9,2}, {32,6,7,85,32,2}};

    for(int i = 0; i<arr.size(); i++){
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int sum = 0;
        for(int j = 0; j<arr[i].size(); j++){
            maxi = max(maxi, arr[i][j]);
            mini = min(mini, arr[i][j]);
            sum += arr[i][j];
        }

        cout << "Values of row: " << i << " Min, Max and Avg: " << mini << " ," << maxi << " ," << sum/arr[i].size() << endl;
    }

    return 0;

}