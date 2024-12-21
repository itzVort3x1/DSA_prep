//------------------------------------
//      Three way partitioning
//      Link: https://geeksforgeeks.org/problems/three-way-partitioning/1
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,3,4};
    int a = 1; 
    int b = 2;

    int start = 0;
    int end = arr.size() - 1;
    int i = 0;

    while(i <= end){
        if(arr[i] < a){
            swap(arr[i], arr[start]);
            start++;
            i++;
        }else if(arr[i] > b){
            swap(arr[i], arr[end]);
            end--;
        }else {
            i++;
        }
    }

    for(int num: arr){
        cout << num << " ";
    }

    cout << endl;

    return 0;
}