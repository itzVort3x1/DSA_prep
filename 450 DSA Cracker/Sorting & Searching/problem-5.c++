//------------------------------------
//      Value equal to index value
//      Link: https://www.geeksforgeeks.org/problems/value-equal-to-index-value1330/1
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = {15,2,45,4,7};

    vector<int> result;

    for(int i = 0; i<arr.size(); i++){
        if(arr[i] == i+1){
            result.push_back(i+1);
        }
    }

    for(int num:result){
        cout << num << " ";
    }

    cout << endl;

    return 0;
}