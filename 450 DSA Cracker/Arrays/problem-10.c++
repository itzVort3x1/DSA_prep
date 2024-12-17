//------------------------------------
//      Find the Duplicate Number
//      Link: https://leetcode.com/problems/find-the-duplicate-number/description/
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1,3,4,2,2};
    for(int i = 0; i < arr.size(); i++){
        int index = abs(arr[i]);

        if(arr[index] < 0){
            cout << "The Duplicate number is: " << index << endl;
            return 0;
        }

        arr[index] *= -1;
    }

    cout << "There is no duplicate number in the array." << endl;
    return 0;
}