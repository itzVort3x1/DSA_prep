//------------------------------------
//      Topological sort (Khan's algorithm)
//------------------------------------

#include<iostream>
using namespace std;

class graph{
    public:
        unordered_map<int, bool> adj;

    void addEdge(int u, int v, bool direction){
        adj[u].push_back(v);

        if(!direction){
            adj[v].push_back(u);
        }
    }

    printAdjList(){
        for(int &i:adj){
            cout << i.first << "-> ";
            for(int j:i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void dfs()

}

int main(){

}