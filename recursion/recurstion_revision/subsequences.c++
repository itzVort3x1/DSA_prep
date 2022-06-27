//------------------------------------
//      Subsequences of String.
//              INPUT: nums = abc
//              OUTPUT: a ab abc ac b bc c
//              EXPLANATION: All possible subsequences of abc are :  
//                          “a” , “b” , “c” , “ab” , “bc” , “ac”, “abc”
//------------------------------------

#include<iostream>
#include<vector>

using namespace std;

void solve(string str, string output, vector<string> &ans, int index){
    //base case
    if(index >= str.length()){
        // this if statement is to exclude empty string.
          if(output.length() > 0){
               ans.push_back(output);
          }
        return;
    }

    //exclude
    solve(str, output, ans, index+1);

    //include
    char element = str[index];
    output.push_back(element);
    solve(str, output, ans, index+1);
}

int main(){
    string str = "abc";
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, ans, index);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}