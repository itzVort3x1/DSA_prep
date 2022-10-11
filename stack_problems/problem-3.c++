//------------------------------------
//      Maximum Rectangular Area in a Histogram
//      GFG Link: https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
//------------------------------------

#include<iostream>
#include<stack>
using namespace std;

class Solution{
     public:

     long long nextSmallerElement(long long arr[], int n){
          stack<int> s;
          s.push(-1);
          long long ans[n];

          for(int i=n-1; i>=0; i++){
               int curr = arr[i];
               while(s.top() >= curr){
                    s.pop();
               }
               arr[i] = s.top();
               s.pop();
          }
          return ans;
     }

     long long getMaxArea(long long arr[], int n){
          long long next[n];
          next = nextSmallerElement(arr, n);
          return next;
     }
};
