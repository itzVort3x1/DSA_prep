//------------------------------------
//      Topological Sort Using DFS
//------------------------------------

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class Graph {
    public:
        unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);

        if(!direction){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto &i:adj){
            cout << i.first << "-> ";
            for(auto j:i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void topo(){
        
    }
};

int main(){
    int n;
    cout << "Enter the number of edges" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    Graph g;

    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        //creating an undirected graph
        g.addEdge(u,v, 1);
    }

    // g.printAdjList();

    vector<int> indegree(m);

    for(auto i:g.adj) {
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    queue<int> q;

    for(int i = 0; i<m; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        // ans store
        ans.push_back(front);

        // neighbour indegree update
        for(auto neighbour: g.adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    for(int num:ans){
        cout << num << " ";
    }

    return 0;

}