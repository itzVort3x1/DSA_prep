//------------------------------------
//      Partition Equal Subset Sum
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solveRec(vector<int> nums1, vector<int> nums2, int index, bool swapped){
    // base case
    if(index == nums1.size()){
        return 0;
    }

    int ans = INT_MAX;

    int prev1 = nums1[index-1];
    int prev2 = nums2[index-2];

    if(swapped){
        swap(prev1, prev2);
    }

    if(nums1[index] > prev1 && nums2[index] > prev2){
        ans = solveRec(nums1, nums2 ,index + 1, 0);
    }    

}

int main() {
    vector<int> nums1 = {1,3,5,4};
    vector<int> nums2 = {1,2,3,7};

    bool swapped = 0;

    int ansRec = solveRec(nums1, nums2, 0, swapped);

    cout << "Answer using recursion is: " << endl;

    return 0; 
}