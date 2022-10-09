//------------------------------------
//      First element to occur k times
//      GFG Link: https://practice.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1?page=1&curated[]=1&sortBy=difficulty
//------------------------------------

#include<iostream>
#include<map>
using namespace std;

int main(){
     int a[] = {1,7,4,3,4,8,7};

     map<int, int> mp;
     map<int, int> :: iterator itr;
     for(int i=0; i<7; i++){
          mp[a[i]]++;
          if(mp[a[i]] == 2){
               cout << a[i] << endl;
               break;
          }
     }

     return 0;
}