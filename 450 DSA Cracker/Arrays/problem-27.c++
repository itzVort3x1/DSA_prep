//------------------------------------
//      Best Sightseeing Pair
//      Link: https://leetcode.com/problems/best-sightseeing-pair/description/
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr={8,1,5,2,6};
    
    int first = arr[0];
    int mps = 0;

    for(int i=1; i<arr.size(); i++){
        int second = arr[i] - i;
        mps = max(mps, first+second);
        first = max(first, arr[i]+i);
    }

    cout << "The maximum pair sum is: " << mps << endl;

    return 0;

}