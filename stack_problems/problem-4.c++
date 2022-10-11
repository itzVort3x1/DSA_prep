//------------------------------------
//      Maximum Rectangular Area in a Histogram
//      Link: https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0
//------------------------------------

#include<iostream>
using namespace std;

void solve(stack<int> &inputStack, int count, int N){
     if(count == N/2){
          inputStack.pop();
          return;
     }

     int num = inputStack.top();
     inputStack.pop();
     solve(inputStack, count + 1, N);
     inputStack.push(num);

}

void deleteMiddle(stack<int> &inputStack, int N){
     int count = 0;
     solve(inputStack, count, N);
}