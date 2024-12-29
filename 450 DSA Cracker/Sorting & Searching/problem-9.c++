//------------------------------------
//      Majority Element
//      Link: https://www.geeksforgeeks.org/problems/majority-element-1587115620/1
//------------------------------------

#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = {3,1,3,3,2};

    int candidate = arr[0];
    int count = 1;

    for(int i=1;i<arr.size(); i++){
        if(candidate == arr[i]){
            count++;
        }else {
            count--;
            if(count == 0){
                candidate = arr[i];
                count = 1;
            }
        }
    }

    count = 0;

    for(int num: arr){
        if(num == candidate){
            count++;
        }
    }

    if(count > arr.size() / 2){
        cout << "Majority Element is: " << candidate << endl;
    }

    return 0;
}