//------------------------------------
//      Factorials of large numbers
//      Link: https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
//------------------------------------

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main () {
    int n = 5;

    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    for(int i = 2; i<=n; i++){
        for(int j = 0; j<ans.size(); j++){
            int x = ans[j] * i + carry;
            ans[j] = x%10;
            carry = x/10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry/=10;
        }
    }
    reverse(ans.begin(), ans.end());
    
    cout << "The factorial is: ";
    for(int num:ans){
        cout << num << ", ";
    }

    cout << endl;
    return 0;
}