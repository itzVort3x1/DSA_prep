//------------------------------------
//      Dijkastra's Algorithm
//------------------------------------

#include<iostream>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;

class Graph{
     public:
          unordered_map<int, list<pair<int, int> > > adj;
          unordered_map<int, bool> visited;
          stack<int> s;
          void addEdge(int u, int v, int w){
               adj[u].push_back(make_pair(v,w));
               adj[v].push_back(make_pair(u,w));
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
          int u, v, w;
          cin >> u >> v >> w;

          g.addEdge(u, v, w);
     }
     cout << endl;
     g.printList();

     vector<int> dist(n);
     for(int i=0; i<n; i++){
          dist[i] = INT_MAX;
     }

     set<pair<int, int> > st;

     dist[src] = 0;
     st.insert(make_pair(0, src));

     while(!st.empty()){
          //fetch top record
          auto top = *(st.begin());

          int nodeDist = top.first;
          int topNode = top.second;

     }

}