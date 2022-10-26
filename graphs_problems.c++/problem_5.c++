//------------------------------------
//      Topological Sort in Graph using DFS
//------------------------------------

#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

class Graph{
     public:
          unordered_map<int, list<int> > adj;
          unordered_map<int, bool> visited;
          unordered_map<int, bool> dfsVisited;
          void addEdge(int u, int v){
               adj[u].push_back(v);
          }

          void printList(){
               for(auto i:adj){
                    cout << i.first << "-> ";
                    for(auto j:i.second){
                         cout << j << ", ";
                    }
                    cout << endl;
               }
          }
};

int main(){
     int n;
     cout << "Enter the number of nodes: ";
     cin >> n;

     int m;
     cout << "Enter the number of edges: ";
     cin >> m;

     Graph g;

     for(int i=0; i<m; i++){
          int u, v;
          cin >> u >> v;

          g.addEdge(u, v);
     }
     cout << endl;
     g.printList();
}