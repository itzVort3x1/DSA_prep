//------------------------------------
//      Course Schedule
//------------------------------------

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}, {0,1}};

    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    vector<int> ans;

    for(auto x:prerequisites) {
        adj[x[0]].push_back(x[1]);
        indegree[x[1]]++;
    }

    queue<int> q;

    for(int i = 0; i<indegree.size(); i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int t = q.front();
        ans.push_back(t);
        q.pop();

        for(auto x:adj[t]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                q.push(x);
            }
        }
    }

    cout << "Is it possible to complete the course?: " << (ans.size() == numCourses) << endl;

    return 0;
}
