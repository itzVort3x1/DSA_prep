//------------------------------------
//      Strings Rotations of Each Other
//      Link: https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
//------------------------------------

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    string s1 = "abcd";
    string s2 = "cdab";

    string str = s2 + '$' + s1 + s1;

    int n = str.length();
    int i = 0;
    int j = 1;
    int m = s2.length();

    vector<int> lps(n,0);

    while(j < n){
        if(str[i] == str[j]){
            lps[j++]=++i;
            if(i==m) {
                cout << "It is a palindrome string" << endl;
                return 0;
            }
        }else if(i)i=lps[i-1];
        else j++;
    }

    cout << "The string is not palindrome" << endl;
    return 0;
}