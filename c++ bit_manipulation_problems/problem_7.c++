//------------------------------------
//      Find the two non-repeating element in an array of repeating elements
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int main(){

     vector<int> arr;
     vector<int> ans;

     arr.push_back(1);
     arr.push_back(2);
     arr.push_back(3);
     arr.push_back(2);
     arr.push_back(1);
     arr.push_back(4);

     sort(arr.begin(), arr.end());
     for(int i=0; i<arr.size() - 1; i = i+2) {
          if(arr[i] != arr[i+1]){
               ans.push_back(arr[i]);
               i=i-1;
          }
     }

     if(ans.size() == 1){
          ans.push_back(arr[arr.size() - 1]);
     }

     for(int i=0; i<ans.size(); i++){
          cout << ans[i] << " ";
     }

     return 0;


}