//------------------------------------
//      Merge Intervals
//      Ex: Input : intervals = [[1,3],[2,6],[8,10],[15,18]]
//          Output :  [[1,6],[8,10],[15,18]]
//------------------------------------

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    int i = 0;
    while(i < n) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        i+=1;

        while(i < n && end >= intervals[i][0]) { 
            end = max(end, intervals[i][1]);
            i+=1;
        }

        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        ans.push_back(temp);
    }

    for(auto interval:ans) {
        cout << "{" << interval[0] << ", " << interval[1] << "}, ";
    }

    return 0;

}