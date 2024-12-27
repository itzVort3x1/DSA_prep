//------------------------------------
//      Palindrom String
//      Link: https://www.geeksforgeeks.org/problems/palindrome-string0817/1
//------------------------------------

#include<iostream>
using namespace std;

int main() {
    string s = "abba";

    int i = 0;
    int j = s.length() - 1;

    while(i<j){
        if(s[i] == s[j]){
            i++;
            j--;
        }else {
            cout << "The given string is not palindrome" << endl;
            return 0;
        }
    }

    cout << "The give string is a palindrome" << endl;
    return 0;

}