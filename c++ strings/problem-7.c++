//------------------------------------
//      Remove all occurences of a substring
//      Ex: INPUT: n = "daabcbaabcbc", part = "abc"
//          OUTPUT: dab
//          EXPLANATION: The following operations are done:
//                          - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
//                          - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
//                          - s = "dababc", remove "abc" starting at index 3, so s = "dab".
//                          Now s has no occurrences of "abc".
//------------------------------------

#include<iostream>

using namespace std;

int main(){
    string s = "daabcbaabcbc";
    string part = "abc";

    while(s.length() !=0 && s.find(part) < s.length()){
        s.erase(s.find(part), part.length());
    }

    cout<<"The final string is: "<<s<<endl;

    return 0;
}