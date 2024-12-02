#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
using namespace std;


class graph{
    public:
        unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool directed){
        adj[u].push_back(v);

        if(!directed){
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

    void bfs(unordered_map<int, bool> &visited, vector<int> &ans, int node){
        queue<int> q;
        q.push(node);

        visited[node] = true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);
            for(auto i:adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void shortestPath(unordered_map<int, int> &parent, unordered_map<int, bool> &visited, int node){
        queue<int> q;
        q.push(node);

        visited[node] = true;
        parent[node] = -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto i:adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    parent[i] = frontNode;
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
        g.addEdge(u,v, 0);
    }

    g.printAdjList();

    vector<int> ans;

    unordered_map<int, bool> visited;

    if(!visited[1]){
        g.bfs(visited, ans, 1);
    }

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout <<endl;

    unordered_map<int, bool> vis;
    unordered_map<int, int> parent;

    if(!vis[1]){
        g.shortestPath(parent, vis, 1);
    }

    cout << "Printing parent" << endl;
    for(int i = 0; i<parent.size(); i++){
        cout << parent[i] << " ";
    }
    cout << endl;

    int s;
    cout << "Enter the source: " << endl;
    cin >> s;

    int d;
    cout << "Enter the destination: " << endl;
    cin >> d;

    vector<int> spf;
    int currentNode = d;
    spf.push_back(d);
    while(currentNode != s){
        currentNode = parent[currentNode];
        spf.push_back(currentNode);
    }

    cout << "Printing the shortest path: " << endl;
    for(int i:spf){
        cout << i << " ";
    }

    cout << endl;

    return 0;

}