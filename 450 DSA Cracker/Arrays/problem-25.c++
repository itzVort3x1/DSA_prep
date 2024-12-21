//------------------------------------
//      Chocolate Distribution Problem
//      Link: https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr={3,4,1,9,56,7,9,12};
    int m = 5;

    sort(arr.begin(), arr.end());
        
    int minDiff = INT_MAX;
    
    for(int i = 0; i<arr.size()-m + 1; i++){
        int l = arr[i];
        int r = arr[i + m - 1];
        
        // cout << i << "-> " << l << " " << r << endl;
        
        int diff = r - l;
        if(diff < minDiff){
            minDiff = diff;
        }
    }
    
    cout << "The minimum difference is: " << minDiff;

    cout << endl;

    return 0;
}