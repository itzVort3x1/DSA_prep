//------------------------------------
//      Topological sort
//------------------------------------
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

template <typename T>
class graph {
    public:
        unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction) {
        // Adds an edge to the graph
        adj[u].push_back(v);

        // If direction is 0, make it undirected
        if (!direction) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        // Print the adjacency list
        for (auto i : adj) {
            cout << i.first << "-> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void topoSort(int node, unordered_map<T, bool> &visited, stack<T> &st) {
        // Mark the node as visited
        visited[node] = true;

        // Traverse all its neighbors
        for (auto neigh : adj[node]) {
            if (!visited[neigh]) {
                topoSort(neigh, visited, st);
            }
        }

        // Push current node to stack
        st.push(node);
    }
};

int main() {
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    graph<int> g;

    cout << "Enter the edges (u -> v): " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // Creating a directed graph
        g.addEdge(u, v, 1);
    }

    // Print the adjacency list
    g.printAdjList();

    unordered_map<int, bool> visited;
    stack<int> s;

    // Perform topological sorting for all nodes
    for (auto i : g.adj) {
        if (!visited[i.first]) {
            g.topoSort(i.first, visited, s);
        }
    }

    // Collect the result from the stack
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    // Print the topological order
    cout << "Topological Sort: ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
