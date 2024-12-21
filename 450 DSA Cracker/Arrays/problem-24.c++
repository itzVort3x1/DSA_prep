//------------------------------------
//      Triplet Sum in Array
//      Link: https://www.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,4,45,6,10,8};
    int target = 13;

    int n = arr.size();

    sort(arr.begin(), arr.end());

    for(int i = 0; i<n; i++){
        int l = i + 1;
        int r = n - 1;

        while(l < r){
            int sum = arr[i] + arr[l] + arr[r];
            if(sum == target){
                cout << "The triplet are: " << arr[i] << ", " << arr[l] << ", " << arr[r] << endl;
                return 0;
            }else if(sum > target){
                r--;
            }else {
                l++;
            }
        }
    }

    cout << "There are no triplets formed" << endl;
    return 0;
}