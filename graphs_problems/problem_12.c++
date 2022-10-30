//------------------------------------
//      Bridges in Graph
//------------------------------------

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
     public:
          unordered_map<int, list<int> > adj;
          vector<int> disc(v, -1);
          vector<int> low(v, -1);
          int parent = -1;
          unordered_map<int, bool> visited;
          int timer = 0;
          void addEdge(int u, int v){
               adj[u].push_back(v);
               adj[v].push_back(u);
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

          void dfs(int node){
               visited[node] = true;
               disc[node] = low[node] = timer++;

               for(auto it:adj[node]){
                    if(it == parent)
               }

          }
};

int main(){

     int v;
     cout << "Enter the number of vertices: ";
     cin >> v;

     int e;
     cout << "Enter the number of edges: ";
     cin >> e;

     Graph g;

     g.addEdge(6, 7);
     g.addEdge(1, 2);
     g.addEdge(1, 0);
     g.addEdge(0, 2);
     g.addEdge(0, 4);
     g.addEdge(5, 4);
     g.addEdge(5, 3);
     g.addEdge(3, 4);

     //dfs
     for(int i=0; i<v; i++){
          if(!g.visited[i]){
               g.dfs(i);
          }
     }

}