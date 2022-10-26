//------------------------------------
//      Cycle Detection in Directed Graph
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

          bool checkCycleDFS(int node){
               visited[node] = 1;
               dfsVisited[node] = 1;

               for(auto it:adj[node]){
                    if(!visited[it]){
                         bool cycleFound = checkCycleDFS(it);
                         if(cycleFound){
                              return true;
                         }
                    }else if(dfsVisited[it]){
                         //visited
                         return true;
                    }
               }
               dfsVisited[node] = false;
               return false;
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

     for(int i=1; i<=n; i++){
          if(!g.visited[i]){
               bool cycleFound = g.checkCycleDFS(i);
               if(cycleFound){
                    cout << "Cycle is present in the graph" << endl;
               }else {
                    cout << "Cycle is not present in the graph" << endl;
               }
          }
     }


}