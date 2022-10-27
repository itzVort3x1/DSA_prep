//------------------------------------
//      Shortest path in undirected graph
//------------------------------------

#include<iostream>
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

class Graph{
     public:
          unordered_map<int, list<int> > adj;
          unordered_map<int, bool> visited;
          unordered_map<int, int> parent;
          queue<int> q;
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

          void bfs(int src){
               q.push(src);
               visited[src] = true;
               parent[src] = -1;

               while(!q.empty()){
                    int frontNode = q.front();
                    q.pop();

                    for(auto i:adj[frontNode]){
                         if(!visited[i]){
                              visited[i] = true;
                              parent[i] = frontNode;
                              q.push(i);
                         }
                    }

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

     //do bfs
     g.bfs(1);

     vector<int> ans;

     //setting target node;
     int currNode = 8;
     ans.push_back(currNode);

     while(currNode != 1){
          currNode = g.parent[currNode];
          ans.push_back(currNode);
     }

     cout << "The shortest path is: ";
     for(int i=ans.size()-1; i>=0; i--){
          cout << ans[i] << " ";
     }
     cout << endl;
}