//------------------------------------
//      Cycle detection in directed graph using BFS
//------------------------------------

#include<iostream();
#include<vector>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class graph{
    public:
        unordered_map<int, list<int>> mp;

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

}

int main() {

}