#include<iostream>
#include<queue>
using namespace std;

int main(){
     // max heap
     priority_queue<int> pq;

     //INSERTION
     pq.push(10);
     pq.push(20);
     pq.push(30);
     pq.push(40);
     pq.push(50);

     cout << "Top element of heap: " << pq.top() << endl;

     pq.pop();

     cout << "Top element of heap: " << pq.top() << endl;

     cout << "Size of max heap: " << pq.size() << endl;

     if(pq.empty()){
          cout << "Heap is empty" << endl;
     }else {
          cout << "Not empty" << endl;
     }

     // min heap
     priority_queue<int, vector<int>, greater<int> > pqm;

     pqm.push(100);
     pqm.push(90);
     pqm.push(70);
     pqm.push(60);
     pqm.push(50);

     cout << "Top element of min heap: " << pqm.top() << endl;

     pqm.pop();
     
     cout << "Top element of min heap: " << pqm.top() << endl;

     cout << "Size of max heap: " << pqm.size() << endl;

     if(pqm.empty()){
          cout << "Heap is empty" << endl;
     }else {
          cout << "Not empty" << endl;
     }

     return 0;
}