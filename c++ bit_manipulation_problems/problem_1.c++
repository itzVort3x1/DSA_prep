//------------------------------------
//      Power set
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int main(){
     vector<string> ans;
     string str = "abc";

     for(int i = 0; i<(1 << str.length()); i++){
          string temp = "";
          for(int j=0; j<str.length(); j++){
               if(i & (1 << j)){
                    temp += str[j];
               }
          }
          // this is if you dont want empty space in your power set
          if(temp.size()){
               ans.push_back(temp);
          }
     }

     // this is to solve lexographically
     sort(ans.begin(), ans.end());
     for (int i=0; i<ans.size(); i++){
          cout << ans[i] << endl;
     }

}