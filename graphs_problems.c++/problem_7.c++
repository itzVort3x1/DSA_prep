//------------------------------------
//      Shortest Path in Directed Acyclic Graphs
//------------------------------------

#include<iostream>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<unordered_map>
#include<limits.h>
using namespace std;

class Graph{
     public:
          unordered_map<int, list<pair<int, int> > > adj;
          unordered_map<int, bool> visited;
          unordered_map<int, int> parent;
          queue<int> q;
          stack<int> s;
          void addEdge(int u, int v, int weight){
               pair<int, int> p = make_pair(v, weight);
               adj[u].push_back(p);
          }

          void printList(){
               for(auto i:adj){
                    cout << i.first << "-> ";
                    for(auto j:i.second){
                         cout << "(" << j.first << "," << j.second << "), ";
                    }
                    cout << endl;
               }
          }

          void dfs(int node){
               visited[node] = true;
               for(auto it:adj[node]){
                    if(!visited[it.first]){
                         dfs(it.first);
                    }
               }
               s.push(node);
          }

          void getShortestPath(int src, vector<int> &dist){
               dist[src] = 0;

               while (!s.empty()){
                    int top = s.top();
                    s.pop();
                    if(dist[top] != INT_MAX){
                         for(auto i:adj[top]){
                              if(dist[top] + i.second < dist[i.first]){
                                   dist[i.first] = dist[top] + i.second;
                              }
                         }
                    }
               }
               
          }

};

int main(){
     // n = 6
     int n;
     cout << "Enter the number of nodes: ";
     cin >> n;

     // int m;
     // cout << "Enter the number of edges: ";
     // cin >> m;

     Graph g;

     g.addEdge(0, 1, 5);
     g.addEdge(0, 2, 3);
     g.addEdge(1, 2, 2);
     g.addEdge(1, 3, 6);
     g.addEdge(2, 3, 7);
     g.addEdge(2, 4, 4);
     g.addEdge(2, 5, 2);
     g.addEdge(3, 4, -1);
     g.addEdge(4, 5, -2);

     cout << endl;
     g.printList();

     //topological sort
     for(int i=0; i<n; i++){
          if(!g.visited[i]){
               g.dfs(i);
          }
     }

     int src = 1;
     vector<int> dist(n);
     for(int i=0; i<n; i++){
          dist[i] = INT_MAX;
     }

     g.getShortestPath(src, dist);

     cout << "Answer is: ";
     for(int i=0; i<dist.size(); i++){
          cout << dist[i] << " ";
     }

     return 0;

}