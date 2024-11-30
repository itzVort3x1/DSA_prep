#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class graph{
    public:
        unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction){
        adj[u].push_back(v);

        if(!direction){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto &i:adj){
            cout << i.first << "-> ";
            for(auto &j:i.second){
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

};

int main() {
    int n;
    cout << "Enter the number of edges" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    graph<int> g;

    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        //creating an undirected graph
        g.addEdge(u,v, 0);
    }

    vector<int> ans;

    unordered_map<int, bool> visited;

    if(!visited[0]){
        g.bfs(visited, ans, 0);
    }

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
    // g.printAdjList();
}