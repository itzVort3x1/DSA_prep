//------------------------------------
//      Meeting Rooms
//      Ex: Input : intervals = [[0,30],[5,10],[15,20]]
//          Output : false
//------------------------------------

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> intervals = {{0,30}, {5,10}, {15,20}};

    sort(intervals.begin(), intervals.end());

    for(int i = 1; i<intervals.size(); i++) {
        if(intervals[i-1][1] > intervals[i][0]) {
            cout << "false" << endl;
            return 0;
        }
    }

    cout << "True" << endl;

    return 0;
}