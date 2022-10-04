#include<iostream>
#include<deque>
using namespace std;

int main(){
     deque<int> q;

     q.push_front(11);
     q.push_back(12);
     cout << q.front() << endl;
}