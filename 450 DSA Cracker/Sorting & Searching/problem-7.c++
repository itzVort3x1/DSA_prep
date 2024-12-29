//------------------------------------
//      Min and Max in Array
//      Link: https://www.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<long long int> arr = {3,2,1,56,10000,167};

    long long int mini = INT_MAX;
    long long int maxi = INT_MIN;

    for(int i = 0; i<arr.size(); i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    cout << mini << " " << maxi << endl;
    return 0;
}