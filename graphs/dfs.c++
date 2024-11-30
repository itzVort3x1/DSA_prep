#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class graph{
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

    void dfs(unordered_map<int, bool> &visited, vector<int> &ans, int node){
        ans.push_back(node);
        visited[node] = true;

        for(auto i:adj[node]){
            if(!visited[i]){
                dfs(visited, ans, i);
            }
        }
    }
};

int main(){
    int n;
    cout << "Enter the number of edges" << endl;
    cin >> n;

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

    if(!visited[0]){
        g.dfs(visited, ans, 0);
    }

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;

}