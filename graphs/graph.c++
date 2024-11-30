#include<iostream>
#include<map>
#include<list>
#include<unordered_map>
#include <queue>
using namespace std;

template <typename T>
class Graph {
     public:
          unordered_map<T, list<T>> adj;

     void addEdge(T u, T v, bool direction){
          // direction = 0 -> undirected, 1 -> directed

          // create an edge form u to v
          adj[u].push_back(v);

          if(!direction){
               adj[v].push_back(u);
          }

     }

     void printAdjList(){
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
     cout << "Enter the number of edges" << endl;
     cin >> n;

     int m;
     cout << "Enter the number of edges" << endl;
     cin >> m;

     Graph<int> g;

     for(int i = 0; i<m; i++){
          int u, v;
          cin >> u >> v;
          //creating an undirected graph
          g.addEdge(u,v, 0);
     }

     g.printAdjList();

}