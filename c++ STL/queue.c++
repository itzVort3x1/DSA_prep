#include<iostream>
#include<queue>

using namespace std;

int main() {
    queue<int> q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    
    cout<<"First element: "<<q.front()<<endl;
    
    q.pop();
    cout<<"First element: "<<q.front()<<endl;
    
    cout<<"size after pop "<<q.size()<<endl;

    return 0;
}