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
          unordered_map<int, bool> visited;
          unordered_map<int, int> parent;
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
};

int main(){

     Graph g;

     g.addEdge(6, 7);
     g.addEdge(1, 2);
     g.addEdge(1, 0);
     g.addEdge(0, 2);
     g.addEdge(0, 4);
     g.addEdge(5, 4);
     g.addEdge(5, 3);
     g.addEdge(3, 4);

     

}