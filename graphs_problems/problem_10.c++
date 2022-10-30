//------------------------------------
//      Minimum spanning tree (Prim's algorithm)
//------------------------------------

#include<iostream>
#include<list>
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

     int V;
     cout << "Enter the number of vertices: ";
     cin >> V;

     int m;
     cout << "Enter the number of Edges: ";
     cin >> m;

     Graph g;

     g.addEdge(0, 1, 5);
     g.addEdge(1, 2, 3);
     g.addEdge(0, 2, 1);

     g.printList();

     vector<int> key(V);
      vector<bool> mst(V);
      for(int i=0;i<V;i++){
          key[i]=INT_MAX;
          mst[i]=false;
      }
      key[0]=0;
      for(int i=0;i<V;i++)
      {
          int mini = INT_MAX;
          int u;
          for(int node=0;node<V;node++)
          {
              if(mst[node]==false && key[node]<mini)
              {
                  mini = key[node];
                  u=node;
              }
          }
      mst[u]=true;
          for(auto newnodes:g.adj[u]){
              int v = newnodes.first;
              int w =newnodes.second;
              if(mst[v]==false && key[v]>w){
                  key[v]=w;
              }
          }
      }
      
     int sum = 0
     cout << "Key vector: " << endl;
     for(int i=0; i<key.size(); i++){
          cout << key[i] << endl;
          sum+=key[i];
     }

     cout << "Sum of minimum spanning tree is: " << sum << endl;

}