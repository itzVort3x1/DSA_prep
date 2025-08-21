//------------------------------------
//      Insert Interval
//      Ex: Input : intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//          Output :  [[1,2],[3,10],[12,16]]
//------------------------------------

#include <iostream>
#include<vector>
using namespace std;

int findLeft(vector<vector<int>> &intervals, int newStart){
    int left = 0;
    int right = intervals.size();

    while(left < right) {
        int mid = left + (right-left)/2;
        if(intervals[mid][1] < newStart) {
            left = mid+1;
        }else {
            right = mid;
        }
    }

    return left;
}

int findRight(vector<vector<int>> &intervals, int newEnd) {
    int left = 0;
    int right = intervals.size();

    while(left < right) {
        int mid = left + (right - left) /2;
        if(intervals[mid][0] <= newEnd) {
            left = mid + 1;
        }else {
            right = mid;
        }
    }

    return left;
}

int main() {
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};

    vector<int> newInterval = {4,8};

    int start = findLeft(intervals, newInterval[0]);
    int end = findRight(intervals, newInterval[1]);

    vector<vector<int>> result;

    for(int i = 0; i<start; i++) {
        result.push_back(intervals[i]);
    }

    int mergedStart = newInterval[0];
    int mergedEnd = newInterval[1];

    for(int i = start; i<end; i++) {
        mergedStart = min(mergedStart, intervals[i][0]);
        mergedEnd = max(mergedEnd, intervals[i][1]);
    }

    result.push_back({mergedStart, mergedEnd});

    for(int i = end; i<intervals.size(); i++) {
        result.push_back(intervals[i]);
    }

    for(auto interval:result) {
        cout << "{" << interval[0] << ", " << interval[1] << "}, ";
    }


    return 0;
}