#include<iostream>
#include<queue>
using namespace std;

int main(){
     //maxheap
     priority_queue<int> pq;

     pq.push(4);
     pq.push(2);
     pq.push(5);
     pq.push(1);

     cout << "Element at top: " << pq.top() << endl;
     pq.pop();
     cout << "Element at top: " << pq.top() << endl;

     //min heap
     priority_queue<int, vector<int>, greater<int> > minheap;

     minheap.push(4);
     minheap.push(2);
     minheap.push(5);
     minheap.push(1);

     cout << "Element at top of minheap: " << minheap.top() << endl;

     return 0;
}