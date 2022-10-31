//------------------------------------
//      Find Duplicate characters in a string
//------------------------------------

#include<iostream>
#include<map>
using namespace std;

int main(){
     
     map<char, int> count;
     string s = "geeksforgeeks";
     for(int i=0; i<s.length(); i++){
          count[s[i]]++;
     }

     for(auto it:count){
          if(it.second > 1){
               cout << it.first << " -> count = " << it.second << endl;
          }
     }

}