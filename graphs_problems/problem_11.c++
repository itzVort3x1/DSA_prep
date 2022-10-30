//------------------------------------
//      Minimum spanning tree (Kruskal's Algorithm using disjoint set and union by rank & path compression)
//------------------------------------

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Graph{
     public:
          unordered_map<int, list<pair<int, int> > > adj;
          unordered_map<int, bool> visited;
          void addEdge(int u, int v, int w){
               adj[u].push_back(make_pair(v,w));
               adj[v].push_back(make_pair(u,w));
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
};

int main(){
     int n;
     cout << "Enter the number of vertices: ";
     cin >> n;

     int m;
     cout << "Enter the number of Edges: ";
     cin >> m;

     Graph g;

     g.addEdge(0, 1, 3);
     g.addEdge(0, 3, 5);
     g.addEdge(1, 2, 1);
     g.addEdge(2, 3, 8);

     g.printList();
}