//------------------------------------
//      Topological sort (Khan's algorithm)
//------------------------------------

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class graph{
    public:
        unordered_map<int, list<int>> adj;
        vector<int> indegree;

    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);

        if(!direction){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto &i:adj){
            cout << i.first << "-> ";
            for(int j:i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void dfs(unordered_map<int, bool> &visited, vector<int> &ans, int node){
        visited[node] = true;
        ans.push_back(node);

        for(int &i:adj[node]){
            if(!visited[i]){
                dfs(visited, ans, i);
            }
        }
    }

    void bfs(unordered_map<int, bool> &visited, vector<int> &ans, int node){
        queue<int> q;
        q.push(node);

        visited[node] = true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);
            for(int i:adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void buildIndegree(){
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
    }

    void khansAlgo(unordered_map<int, bool> &visited, vector<int> &ans, int node){
        queue<int> q;
        for(int i = 0; i<6; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto neigh:adj[front]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
    }

};

int main(){
    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    graph g;

    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        //creating an undirected graph
        g.addEdge(u,v, 1);
    }

    g.printAdjList();

    vector<int> ans;

    unordered_map<int, bool> visited;

    cout << "printing dfs" << endl;
    if(!visited[0]){
        g.dfs(visited, ans, 0);
    }

    cout << "Printing Bfs" << endl;
    if(!visited[0]){
        g.bfs(visited, ans, 0);
    }

    for(auto i:ans){
        cout << i << endl;
    }

    cout << endl;

    return 0;

}