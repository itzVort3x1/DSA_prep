//------------------------------------
//      Final Array State After K Multiplication Operations 1
//      Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/
//------------------------------------

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    vector<int> arr={2,1,3,5,6};
    int k = 5;
    int multiplier = 2;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> ans;

    for(int i=0; i<arr.size(); i++){
        pq.push({ arr[i], i});
    }

    while(k > 0){
        pair<int, int> temp = pq.top();
        arr[temp.second] = arr[temp.second] * multiplier;
        pq.push({arr[temp.second], temp.second});
        pq.pop();
        k--;
    }

    cout << "The modified vector is: ";
    for(int num:arr) {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}