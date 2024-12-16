//------------------------------------
//      kth smallest
//      Link: https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
//------------------------------------

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {7,10,4,3,20,15};

    int k = 3;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i:arr){
        pq.push(i);
    }

    int i = 1;
    while(i < k){
        pq.pop();
        i++;
    }

    cout << "The kth smallest element is: " << pq.top() << endl;

    return 0;
}