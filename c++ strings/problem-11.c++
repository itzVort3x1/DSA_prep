//------------------------------------
//      Find the Index of the First Occurrence in a String (Needle in a haystack problems)
//------------------------------------

#include<iostream>
using namespace std;

int main() {
    
    string haystack = "sadbutsad";
    string needle = "sad";

    if(needle.empty()){
        cout << "-1" << endl;
        return 0;
    }

    for(int i = 0; i<haystack.size(); i++){
        if(haystack.substr(i, needle.size()) == needle){
            cout << "First Occurance found at: " << i << endl;
            return 0;
        }
    }

    cout << "No substring found: " << -1 << endl;

    return 0;

}