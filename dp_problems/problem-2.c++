//------------------------------------
//      Minimum Cost Climbing Stairs
//      Ex: INPUT: n = 10
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

// N Distinct ways to reach the nth stairs
int nDistWays(int n, int i){
    if(n == i){
        return 1;
    }

    if(i > n){
        return 0;
    }

    int cost = nDistWays(n, i+ 1) + nDistWays(n, i+2);

    return cost;
}

int minCost(vector<int> &cost, int n){
    if(n == 0){
        return cost[0];
    }

    if(n == 1){
        return cost[1];
    }

    int ans = cost[n] + min(minCost(cost, n - 1), minCost(cost, n-2));
    return ans;
}


int main() {
    int n = 3;
    vector<int> cost = {10,15,20};

    int res= nDistWays(n, 0);

    int ans = min(minCost(cost, n - 1), minCost(cost, n - 2));

    cout << "The answer using recursion: " << res << endl;
    cout << "The answer of min cost is: " << ans << endl;

    return 0;

}