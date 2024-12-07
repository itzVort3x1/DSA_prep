//------------------------------------
//      Dijkstra's Algorithm
//------------------------------------

#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<set>
#include<limits.h>
using namespace std;

class Graph {
    public:
        unordered_map<int, list<pair<int, int>>> adj;

        void addEdge(int u, int v, int weight, int directed){
            adj[u].push_back({v, weight});

            if(!directed){
                adj[v].push_back({u, weight});
            }
        }

        void printAdjList(){
            for(auto i:adj){
                cout << i.first << "-> ";
                for(auto j:i.second){
                    cout << "(" << j.first << " , " << j.second << ") ";
                }
                cout << endl;
            }
        }

        void Dijkstra(vector<int> &dist, set<pair<int, int>> &st, int src){
            dist[src] = 0;
            st.insert(make_pair(0, src));

            while(!st.empty()){
                // fetch top record
                auto top = *(st.begin());

                int nodeDist = top.first;
                int topNode = top.second;

                // remving top
                st.erase(st.begin());

                // traverse on neigh
                for(auto neigh:adj[topNode]){
                    if(nodeDist + neigh.second < dist[neigh.first]){
                        auto record = st.find(make_pair(dist[neigh.first], neigh.first));
                        if(record != st.end()){
                            st.erase(record);
                        }

                        // updated distance
                        dist[neigh.first] = nodeDist + neigh.second;

                        st.insert(make_pair(dist[neigh.first], neigh.second));
                    }
                }

            }
        }
};

int main() {

    Graph g;

    g.addEdge(1, 3, 2, 0);
    g.addEdge(3, 2, 6, 0);
    g.addEdge(1, 2, 9, 0);
    g.addEdge(1, 0, 5, 0);
    g.addEdge(2, 0, 8, 0);

    g.printAdjList();

    vector<int> dist(5);
    for(int i = 0; i<5; i++){
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    g.Dijkstra(dist, st, 0);

    for(int i = 0; i<dist.size(); i++){
        cout << dist[i] << " ";
    }

    return 0;
}