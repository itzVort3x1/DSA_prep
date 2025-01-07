//------------------------------------
//      Range Addition
//      Link: https://leetcode.com/problems/shifting-letters-ii/description/
//------------------------------------

#include <iostream>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>> shifts = {{0,1,0},{1,2,1},{0,2,1}};
    string s = "abc";

    int n = s.size();
    vector<int> diff(n+1, 0);

    for(auto shift:shifts){
        if(shift[2] == 1){
            diff[shift[0]]++;
            diff[shift[1] + 1]--;
        }else {
            diff[shift[0]]--;
            diff[shift[1] + 1]++;
        }
    }

    for(int i = 1; i<=n; i++){
        diff[i] += diff[i-1];
    }

    string res;
    for(int i=0; i<n; i++){
        int count = diff[i]%26;
        if(count < 0){
            count = 26+count;
        }

        char curr = char((s[i] - 'a' + count)%26 + 97);
        res.push_back(curr);
    }

    cout << "The resultant string is: " << res << endl;

    cout << endl;

    return 0;

}
