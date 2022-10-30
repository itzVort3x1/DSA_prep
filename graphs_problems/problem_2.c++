//------------------------------------
//      Graph BFS Traversal
//------------------------------------

#include<iostream>
#include<map>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph{
     public:
     unordered_map<int, list<int> > adj;
     vector<int> ans;
     unordered_map<int, bool> visited;
     void addEdge(int u, int v){
          adj[u].push_back(v);
          adj[v].push_back(u);
     };

     void printList(){
          for(auto i:adj){
               cout << i.first << " -> ";
               for(auto j:i.second){
                    cout << j << ", ";
               }
               cout << endl;
          }
     }

     void printBFS(){
          for(int i=0; i<ans.size(); i++){
               cout << ans[i] << " ";
          }
     }

     void bfs(int i){
          queue<int> q;
          q.push(i);
          visited[i] = 1;

          while(!q.empty()){
               int frontNode = q.front();
               q.pop();
               ans.push_back(frontNode);

               for(auto i:adj[frontNode]){
                    if(!visited[i]){
                         q.push(i);
                         visited[i] = 1;
                    }
               }
          }
     }
};

int main(){
     int n;
     cout << "Enter the number of Nodes: ";
     cin >> n;

     int m;
     cout << "Enter the number of Edges: ";
     cin >> m;

     Graph g;

     for(int i=0; i<m; i++){
          int u, v;
          cin >> u >> v;

          g.addEdge(u, v);
     }
     cout << endl;
     g.printList();
     cout << endl;
     for(int i=0; i<n; i++){
          if(!g.visited[i]){
               `g.bfs(i);
          }
     }
     cout << endl;
     g.printBFS();
}