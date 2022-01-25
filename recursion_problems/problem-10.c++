//------------------------------------
//      PROBLEM LINK: https://leetcode.com/problems/permutations/
//      Permutations
//              INPUT: nums = [1,2,3]
//              OUTPUT: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//------------------------------------

#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int index){
    //base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=index; i<nums.size(); i++){
        swap(nums[index], nums[i]);
        solve(nums, ans, index+1);
    }
}

int main(){
    cout<<"Enter size of Array: ";
    int size;
    cin>>size;
    vector<vector<int>> ans;
    vector<int> nums;
    for(int i=0; i<size; i++){
        int input;
		cin >> input;
		nums.push_back(input);
    }
    int index = 0;
    solve(nums, ans, index);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}