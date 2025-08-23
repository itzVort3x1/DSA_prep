//------------------------------------
//      Palindromic Substring
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int solve(string s, int i, int j) {
    int count = 0;
    while(i >= 0 && j < s.length() && s[i] == s[j]) {
        count++;
        i--;
        j++;
    }

    return count;
}

int main() {
    string s = "aaa";

    int totalCount = 0;

    for(int center = 0; center < s.length(); center++) {
        int oddLen = solve(s, center, center+1);
        int evenLen = solve(s, center, center);
        totalCount = totalCount + oddLen + evenLen;
    }

    cout << "Total Palindromes are: " << totalCount << endl;

    return 0;
}
