//------------------------------------
//      Minimum spanning tree (Kruskal's Algorithm using disjoint set and union by rank & path compression)
//------------------------------------

#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
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

          void makeSet(vector<int> &parent, vector<int> &rank, int n){
               for(int i=0; i<n; i++){
                    parent[i] = i;
                    rank[i] = 0;
               }
          }

          int findParent(vector<int> &parent, int node){
               if(parent[node] == node){
                    return node;
               }
               return parent[node] = findParent(parent, parent[node]);
          }

          void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
               u = findParent(parent, u);
               v = findParent(parent, v);

               if(rank[u] < rank[v]){
                    parent[u] = v;
               }else if(rank[v] < rank[u]){
                    parent[v] = u;
               }else {
                    parent[v] = u;
                    rank[u]++;
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

     g.addEdge(1, 2, 1);
     g.addEdge(0, 1, 3);
     g.addEdge(0, 3, 5);
     g.addEdge(2, 3, 8);

     g.printList();

     vector<int> parent(n);
     vector<int> rank(n);
     g.makeSet(parent, rank, n);

     int minWeight = 0;

     for(int i=0; i<m; i++){
          int u = g.findParent(parent, g.adj[u].first);
          int v = g.findParent(parent, g.adj[v].second.first);
          int wt = g.adj[v].second.second;

          if(u != v){
               minWeight += wt;
               g.unionSet(u, v, parent, rank);
          }

     }

     cout << "Minium weight: " << minWeight << endl;

}