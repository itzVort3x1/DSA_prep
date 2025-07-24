//------------------------------------
//      Topological Sort Using DFS
//------------------------------------

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
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

    void topo(int node, unordered_map<int, bool> &visited, stack<int> &st){
        visited[node] = 1;
        
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                topo(neighbour, visited, st);
            }
        }

        st.push(node);
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

    g.printAdjList();

    vector<int> ans;

    stack<int> st;
    unordered_map<int, bool> visited;

    for(int i = 1; i<m; i++){
        if(!visited[i]){
            g.topo(i, visited, st);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;

}