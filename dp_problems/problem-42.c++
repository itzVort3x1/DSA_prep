//------------------------------------
//      Longest Palindromic Substring
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s = "babad";

    string res = "";
    int resLen = 0;

    for(int i=0; i<s.length(); i++) {
        //odd length
        int l = i;
        int r = i;
        while(l >=0 && r < s.length() && s[l] == s[r]) {
            if((r-l+1) > resLen) {
                res = s.substr(l, r-l + 1);
                resLen = r-l+1;
            }
            l-=1;
            r+=1;
        }

        // even length
        l = i;
        r = i+1;
        while(l>=0 && r < s.length() && s[l] == s[r]) {
            if(r-l+1 > resLen) {
                res = s.substr(l, r-l+1);
                resLen = r-l+1;
            }
            l-=1;
            r+=1;
        }
    }

    cout << "The Longest Palindromic Substring is: " << res << endl;

    return 0;
}