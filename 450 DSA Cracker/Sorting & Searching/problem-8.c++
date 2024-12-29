//------------------------------------
//      Missing And Repeating
//      Link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = {2,2};
    vector<int> res;

    int n = arr.size();

    for(int i = 0; i<n; i++){
        int element = abs(arr[i]);
        if(arr[element-1]<0)res.push_back(element);
        else arr[element-1]*=-1;
    }

    for(int i = 0; i<n; i++){
        if(arr[i]>0)res.push_back(i+1);
    }
    
    for(int num:res){
        cout << num << " ";
    }

    cout << endl;
    return 0;
}