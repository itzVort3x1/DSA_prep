//------------------------------------
//      Print Anagrams Together
//      Link: https://www.geeksforgeeks.org/problems/print-anagrams-together/1
//------------------------------------

#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> arr = { "act", "god", "cat", "dog", "tac"};

    vector<vector<string> > result;

        // hash map to maintain groups of anagrams
    unordered_map<string, vector<string> > umap;

    for (int i = 0; i < arr.size(); i++) {
        string s = arr[i];

        // sort each string
        sort(s.begin(), s.end());

        // add original string to corresponding sorted string in hash map
        umap[s].push_back(arr[i]);
    }
    for (auto itr = umap.begin(); itr != umap.end(); itr++){
        result.push_back(itr->second);
    }

    for(auto i:result){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    
    cout << endl;

    return 0;

}