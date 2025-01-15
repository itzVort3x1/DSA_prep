//------------------------------------
//      Maximum Height by stacking cuboid
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<vector<int>> arr, int n, int curr, int prev){
    if(curr == n){
        return 0;
    }

    int include = 0;
    if(prev == -1 || arr[curr] > arr[prev]){
        include = arr[curr][2] + solveRec(arr, n, curr+1, curr);
    }

    int exclude = solveRec(arr, n, curr+1, prev);

    int ans = max(include, exclude);

    return ans;
}

int main() {
    vector<vector<int>> cuboids = {{50,45,20},{95,37,53},{45,23,12}};

    // sort all dimensions
    for(auto &a: cuboids){
        sort(a.begin(), a.end());
    }

    //sort all cuboids basis on w or l
    sort(cuboids.begin(), cuboids.end());

    // use LIS logic
    int ansRec = solveRec(cuboids, cuboids.size(), 0, -1);

    cout << "Answer using recursion is: " << ansRec << endl;

    return 0;
}

