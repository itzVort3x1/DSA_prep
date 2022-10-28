#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

int main(){

     int n=5;
     int e = 5;
     vector<pair<int, int> > edges;

     edges.push_back(make_pair(0,3));
     edges.push_back(make_pair(3,4));
     edges.push_back(make_pair(0,4));
     edges.push_back(make_pair(0,1));
     edges.push_back(make_pair(1,2));

     //adj list
     unordered_map<int, list<int> > adj;

     for(int i=0; i<edges.size(); i++){
          int u = edges[i].first;
          int v = edges[i].second;

          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     int timer = 0;
     vector<int> disc(n);
     vector<int> low(n);
     unordered_map<int, bool> vis;
     vector<int> ap(n,0);


     return 0;
}