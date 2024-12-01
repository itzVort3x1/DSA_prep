//------------------------------------
//      cycle detection in Directed graph
//------------------------------------

#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

template <typename T>
class graph {
    public:
        unordered_map<T, list<T>> adj;

    void addEdge(T u,T v, bool direction){
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

    bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto i:adj[node]){
            if(!visited[i]){
                bool cycleDetected = checkCycleDFS(i, visited, dfsVisited);
                if(cycleDetected){
                    return true;
                }
            }else if(dfsVisited[i]) {
                return true;
            }
        }

        dfsVisited[node] = false;
        return false;
    };
    
};

int main(){

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    graph<int> g;

    for(int i = 0; i<m; i++){
        int u, v;
        cin >> u >> v;
        //creating an undirected graph
        g.addEdge(u,v, 1);
    }

    g.printAdjList();

    vector<int> ans;

    unordered_map<int, bool> visited;

    // cout << "printing dfs" << endl;
    // if(!visited[0]){
    //     g.dfs(visited, ans, 0);
    // }

    unordered_map<int, bool> dfsVisited;

    if(!visited[0]){
        bool cycleFound = g.checkCycleDFS(0, visited, dfsVisited);
        if(cycleFound){
            cout << "Cycle detected" << endl;
        }
    }

    // for(int i = 0; i<ans.size(); i++){
    //     cout << ans[i] << " ";
    // }

    cout << endl;

    return 0;

}