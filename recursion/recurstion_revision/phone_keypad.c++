#include<iostream>
#include<vector>
using namespace std;

void solve(string digits, int index, string output, vector<string> &ans, string mapping[]){
     //base case
     if(index >= digits.length()){
          ans.push_back(output);
          return;
     }

     int number = digits[index] - '0';
     string value = mapping[number];
     for(int i=0; i<value.length(); i++){
          output.push_back(value[i]);
          solve(digits, index+1, output, ans, mapping);
          output.pop_back();
     }

}

void print(vector<string> ans){
     for(int i=0; i<ans.size(); i++){
          cout << ans[i] << " ";
     }
}

int main(){
     string digits;
     cout<<"Enter a number: ";
     cin>>digits;

     vector<string> ans;
     if(digits.length() == 0){
          print(ans);
     }
     int index = 0;
     string output = "";
     string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

     solve(digits, index, output, ans, mapping);

     print(ans);
}