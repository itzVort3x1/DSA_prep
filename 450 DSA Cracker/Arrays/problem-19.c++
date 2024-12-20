//------------------------------------
//      Subarray with 0 sum
//      Link: https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
//------------------------------------

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    vector<int> arr = {4,2,-3,1,6};

    unordered_map<int, bool> mp;

    int sum = 0;
    mp[sum] = true;

    for(int num:arr){
        sum += num;

        if(mp[sum]){
            cout << "Subarray exists" << endl;
            return 0;
        }
        mp[sum] = true;
    }

    cout << "Subarray does not exists" << endl;

    return 0;
}