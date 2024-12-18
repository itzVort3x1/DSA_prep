//------------------------------------
//      Merge Intervals
//      Link: https://leetcode.com/problems/merge-intervals/description/
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> ans;

    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    int i = 0;
    while(i < n){
        int start = intervals[i][0];
        int end = intervals[i][1];
        i+=1;

        while(i<n && end >= intervals[i][0]){
            end = max(end, intervals[i][1]);
            i+=1;
        }

        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        ans.push_back(temp);
    }

    for(vector<int> num:ans){
        cout << num[0] << ", " << num[1] << endl;
    }

    return 0;

}