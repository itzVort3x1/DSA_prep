//------------------------------------
//      Kth largest sum subarray
//------------------------------------

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
    int arr[] = {1,2,6,4,3};
    int kth = 3;
    int n = 5;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i<n; i++){
        int sum = 0;

        for(int j = i; j<n; j++){
            sum += arr[j];
            if(pq.size() < kth){
                pq.push(sum);
            }else {
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    cout << "Kth Largest: " << pq.top() << endl;

}