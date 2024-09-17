#include<iostream>
#include<unordered_map>
#include<map>
#include<stack>
#include<list>
#include<queue>
using namespace std;

class Graph {
     public:
          unordered_map<int, list<int> > adj;

          void addEdge(int u, int v, bool direction){
               if(direction == 1){
                    adj[u].push_back(v);
               }else {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
               }
          }

          void printAdjList() {
               for(auto i: adj){
                    cout << i.first << ": {";
                    for(auto j: i.second){
                         cout << j << ",";
                    }
                    cout << "}" << endl;
               }
          }

          void topoSortDfs(int src, map<int, bool> &visited, stack<int> &st){
               visited[src] = true;

               for(auto nbr:adj[src]){
                    if(!visited[nbr]){
                         topoSortDfs(nbr, visited, st);
                    }
               }

               st.push(src);
          }

          void topoSortBfs(int n) {
               queue<int> q;
               map<int, int> indegree;
               for(auto i: adj){
                    for(auto nbr: i.second){
                         indegree[nbr]++;
                    }
               }

               // push all zero indegree node into queue
               for(int node = 0; node <n; node++){
                    if(indegree[node] == 0){
                         q.push(node);
                    }
               }

               // BFS 
               while(!q.empty()){
                    int frontNode = q.front();
                    q.pop();
                    cout << frontNode << ", ";

                    for(auto nbr: adj[frontNode]){
                         indegree[nbr]--;

                         if(indegree[nbr] == 0){
                              q.push(nbr);
                         }
                    }
               }
          }
};

int main() {

     Graph g;
     g.addEdge(0,1,1);
     g.addEdge(1,2,1);
     g.addEdge(2,3,1);
     g.addEdge(2,4,1);
     g.addEdge(3,5,1);
     g.addEdge(4,5,1);
     g.addEdge(5,6,1);
     g.addEdge(5,7,1);

     g.printAdjList();
     g.topoSortBfs(8);

     int n = 8;

     map<int, bool> visited;
     stack<int> st;
     for(int node=0; node<n; node++){
          if(!visited[node]){
               g.topoSortDfs(node, visited, st);
          }
     }

     cout << "Printing the topo order: " << endl;

     while(!st.empty()){
          cout << st.top() << " ";
          st.pop();
     }
     
     return 0;
}