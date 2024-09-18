#include<iostream>
#include<iostream>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<stack>
#include<list>
#include<queue>
using namespace std;

class Graph {
     public:
          unordered_map<int, list<int> > adj;

          void addEdge(int u, int v, bool direction){
               if(direction == 1){
                    adj[u].push_back(v);
               }else {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
               }
          }

          void printAdjList() {
               for(auto i: adj){
                    cout << i.first << ": {";
                    for(auto j: i.second){
                         cout << j << ",";
                    }
                    cout << "}" << endl;
               }
          }

          void shortestPathFirstBfs(int src, int dest){
               queue<int> q;

               map<int, bool> visited;
               map<int, int> parent;

               q.push(src);
               visited[src] = true;
               parent[src] = -1;

               while(!q.empty()){
                    int frontNode = q.front();
                    q.pop();

                    for(auto nbr: adj[frontNode]){
                         if(!visited[nbr]){
                              q.push(nbr);
                              parent[nbr] = frontNode;
                              visited[nbr] = true;
                         }
                    }
               }

               //parent array 
               vector<int> ans;
               while(dest != -1){
                    ans.push_back(dest);
                    dest = parent[dest];
               }

               reverse(ans.begin(), ans.end());

               for(auto i: ans){
                    cout << i << " ";
               }
          }
};

int main() {

     Graph g;
     g.addEdge(0, 5, 0);
     g.addEdge(5, 4, 0);
     g.addEdge(4, 3, 0);
     g.addEdge(0, 6, 0);
     g.addEdge(6, 3, 0);
     g.addEdge(0, 1, 0);
     g.addEdge(1, 2, 0);
     g.addEdge(2, 3, 0);

     int n = 7;
     int src = 0;
     int dest = 3;

     g.shortestPathFirstBfs(src, dest);

     return 0;
}