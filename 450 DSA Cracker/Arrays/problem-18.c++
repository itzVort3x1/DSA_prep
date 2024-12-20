//------------------------------------
//      Two sum -Pairs with 0 Sum
//      Link: https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
//------------------------------------

#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};

    sort(arr.begin(), arr.end());

    unordered_set<int> seen;

    set<pair<int, int>> result;

    for(int num: arr){
        int complement = -num;

        if(seen.find(complement) != seen.end()){
            result.insert({min(num, complement), max(num, complement)});
        }

        seen.insert(num);
    }

    for(auto &pair:result){
        cout << pair.first << ", " << pair.second;
    }

    cout << endl;
    return 0;
}