//------------------------------------
//      Non-Overlapping Intervals
//      Ex: Input : intervals = [[1,2],[2,3],[3,4],[1,3]]
//          Output : 1
//------------------------------------

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};

    sort(intervals.begin(), intervals.end());

    int count = 0;
    int end = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] >= end) {
            end = intervals[i][1];
        }else {
            count+=1;
            end = min(end, intervals[i][1]);
        }
    }

    cout << "The number of intervals required to be removed are: " << count << endl;

    return 0;
}