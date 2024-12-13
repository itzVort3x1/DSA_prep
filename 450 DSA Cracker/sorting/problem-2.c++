//------------------------------------
//      Sorted and Rotated Minimum
//      Link: https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> arr = {5,6,1,2,3,4};
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int mid = low + (high-low)/2;

    while(low < high){
        if(arr[mid] < arr[high]){
            high = mid;
        }else {
            low = mid + 1;
        }
        mid = low + (high-low)/2;
    }

    cout << "The minimum element is: " << arr[low] << endl;

    return 0;

}