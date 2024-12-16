//------------------------------------
//      Sort 0s, 1s and 2s
//      Link: https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr={0,1,2,0,1,2};
    int low = 0;
    int mid = 0;
    int high = arr.size() -1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }else if(arr[mid] == 1){
            mid++;
        }else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    cout << "The sorted array is: ";
    for(int num:arr){
        cout << num << " ";
    }

    cout << endl;
    return 0;
}