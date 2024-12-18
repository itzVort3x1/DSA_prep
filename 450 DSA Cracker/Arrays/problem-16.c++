//------------------------------------
//      Longest Consecutive Subsequence
//      Link: https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
//------------------------------------

#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {2,6,1,9,4,5,3};

    unordered_set<int> uniqueElements(arr.begin(), arr.end());
    vector<int> uniqueArr(uniqueElements.begin(), uniqueElements.end());

    sort(uniqueArr.begin(), uniqueArr.end());

    int longsubseq = 1;
    int curr = 1;
    for(int i = 1; i<uniqueArr.size(); i++){
        if(uniqueArr[i] - uniqueArr[i-1] == 1){
            curr++;
        }else {
            longsubseq = max(longsubseq, curr);
            curr = 1;
        }
    }

    longsubseq = max(longsubseq, curr);

    cout << "The longes subseques is: " << longsubseq << endl;

    return 0;

}