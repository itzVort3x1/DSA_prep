#include<iostream>
#include<map>
#include<list>
#include<unordered_map>
#include <queue>
using namespace std;

template <typename T>
class Graph{
     public:
          unordered_map<T, list<T> > adjlist;
          unordered_map<T, list<pair<T,int> > > adjlist2;

          void addEdge(T u, T v, bool direction){
               // direction -> 0 -> undirected
               // direction -> 1 -> directed

               if(direction == 1){
                    // u se v ke taraf 
                    // u->v
                    adjlist[u].push_back(v);
               }else {
                    // u -- v
                    adjlist[u].push_back(v);
                    adjlist[v].push_back(u);
               }

               cout << endl << "Printing adj list" << endl;
               printAdjList();
               cout << endl;
          }

          void printAdjList(){
               for(auto i:adjlist){
                    cout << i.first << "-> {";
                    for(auto neigh:i.second){
                         cout << neigh << ",";
                    }
                    cout << "}" << endl;
               }
          }      

          void addWeightedEdge(T u, T v, int wt, bool direction){
               // direction = 0 -> undirected
               // direction = 1 -> directed
               if(direction == 1){
                    adjlist2[u].push_back(make_pair(v, wt));
               }else {
                    adjlist2[u].push_back(make_pair(v, wt));
                    adjlist2[v].push_back(make_pair(u, wt));
               }
               cout << endl << "Printing weighted adj list" << endl;
               printWeightedAdjList();
               cout << endl;
          }

          void printWeightedAdjList() {
               for(auto i:adjlist2){
                    cout << i.first << "->{";
                    for(pair<T,int> p:i.second){
                         cout << "{" << p.first << ", " << p.second << "}, ";
                    }
                    cout << "}" << endl;
               }
          }

          void bfsTraversal(T src, unordered_map<T, bool> &vis){
               queue<T> q;
               q.push(src);
               vis[src] = true;

               while(!q.empty()){
                    T frontNode = q.front();
                    cout << frontNode << " ";
                    q.pop();

                    for(auto nbr: adjlist2[frontNode]){
                         T nbrData = nbr.first;

                         if(!vis[nbrData]){
                              q.push(nbrData);
                              vis[nbrData] = true;
                         }
                    }
               }
          }
};

int main(){

     Graph<char> g;

     g.addWeightedEdge('a','b',5,0);
     g.addWeightedEdge('b','c',10,0);
     g.addWeightedEdge('d','e',20,0);
     g.addWeightedEdge('f','f',30,0);
     // g.addWeightedEdge('c','e',30,0);
     // g.addWeightedEdge('e','f',30,0);

     unordered_map<char, bool> vis;
     for(char node ='a'; node <= 'f'; node++){
          if(!vis[node]){
               g.bfsTraversal(node, vis);
          }
     }

     return 0;

}