//------------------------------------
//      Meeting Rooms 2
//      Ex: Input : intervals = [[0,30],[5,10],[15,20]]
//          Output : false
//------------------------------------

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> intervals = {{0,30}, {5,10}, {15,20}};

    vector<int> start;
    vector<int> end;

    for(int i = 0; i<intervals.size(); i++) {
        start.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int startPointer = 0;
    int endPointer = 0;
    int useRooms = 0;

    while(startPointer < intervals.size()) {
        if(start[startPointer] >= end[endPointer]) {
            useRooms -= 1;
            endPointer +=1;
        }

        useRooms += 1;
        startPointer +=1;
    }

    cout << "The number of rooms required are: " << useRooms << endl;

    return 0;

}