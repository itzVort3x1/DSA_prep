//------------------------------------
//      Array Subset
//      Link: https://www.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
//------------------------------------

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> a = {11,7,1,13,21,3,7,3};
    vector<int> b = {11,3,7,1,7};

    unordered_map<int, int> mp;

    for(int i:a){
        mp[i] = 1;
    }

    for(int i:b){
        if(!mp[i]){
            cout << "B is not a subset of A" << endl;
            return 0;
        }
    }

    cout << "B is a subset of A" << endl;
    return 0;
}