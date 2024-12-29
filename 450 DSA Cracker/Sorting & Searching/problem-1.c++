//------------------------------------
//      Number of occurence
//      Link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> arr = {1,1,2,2,2,2,3,3};
    int target = 2;

    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n-1;
    int firstIndex = -1;
    int lastIndex = -1;
    for(int i = 0; i<2; i++){
        low = 0;
        high = n-1;
        while(low <= high){
            mid = low + (high-low)/2;
            if(arr[mid] == target){
                if(i==0){
                    firstIndex = mid;
                    high = mid-1;
                }else {
                    lastIndex = mid;
                    low=mid+1;
                }
            }
            else if(arr[mid] > target)high = mid - 1;
            else low = mid + 1;
        }
    }
    if(firstIndex == -1){
        cout << "Answer is: 0" << endl; 
    }

    cout << "The count is: " << lastIndex - firstIndex + 1 << endl;

    return 0;
}