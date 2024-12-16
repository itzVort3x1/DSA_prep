//------------------------------------
//      Move all negative elements to end
//      Link: https://www.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1
//------------------------------------

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<int> arr = {1,-1,3,2,-7,-5,11,6};
    int n = arr.size();
    stack<int> pos;
    stack<int> neg;

    for(int i = 0; i<n; i++){
        if(arr[i] < 0){
            neg.push(arr[i]);
        }else {
            pos.push(arr[i]);
        }
    }

    int i = n - 1;

    while(!neg.empty()){
        arr[i--] = neg.top();
        neg.pop();
    }

    while(!pos.empty()){
        arr[i--] = pos.top();
        pos.pop();
    }

    cout << "The sorted array is: ";
    for(int num:arr){
        cout << num << " ";
    }

    cout << endl;

    return 0;
}