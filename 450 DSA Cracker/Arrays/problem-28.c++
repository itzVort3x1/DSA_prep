//------------------------------------
//      Range Addition
//      Link: https://leetcode.com/problems/range-addition/description/ (Premium Problem)
//      Link: https://www.lintcode.com/problem/903/description (Free access)
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> updates = {{1,  3,  2},{2,  4,  3},{0,  2, -2}};
    int length = 5;

    vector<int> gradient(length+1, 0);

    for(auto v:updates){
        gradient[v[0]] += v[2];
        gradient[v[1] + 1] -= v[2];
    }

    for(int i = 1; i<gradient.size(); i++){
        gradient[i] += gradient[i-1];
    }

    gradient.pop_back();

    for(int i=0; i<gradient.size(); i++){
        cout << gradient[i] << " ";
    }

    cout << endl;

    return 0;
}
