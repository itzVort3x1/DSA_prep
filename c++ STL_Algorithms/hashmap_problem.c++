#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){

     int arr[7] = {1,2,3,4,2,3,4};

     unordered_map<int, int> count;

     int maxFreq = 0;
     int maxAns = 0;

     for(int i=0; i<7; i++){
          count[arr[i]]++;
          maxFreq = max(maxFreq, count[arr[i]]);
     }

     for(int i=0; i<7; i++){
          if(maxFreq == count[arr[i]]){
               maxAns = arr[i];
               break;
          }
     }

     return maxAns;

}