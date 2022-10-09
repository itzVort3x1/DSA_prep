//------------------------------------
//      Find duplicated in an array
//------------------------------------

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
     int arr[] = {2,3,1,2,3};
     vector<int> ans;
     unordered_map<int, int> mp;
     for(int i=0; i<5; i++){
          mp[arr[i]]++;
     }
     for(auto it:mp){
          if(it.second > 1){
               ans.push_back(it.first);
          }
     }
     std::sort(ans.begin(), ans.end());
     if(ans.size() == 0){
          ans.push_back(-1);
     }

}