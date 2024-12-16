//------------------------------------
//      Rotate Array by One
//      Link: https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
//------------------------------------

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1,2,3,4,5};

    int n = arr.size() - 1;
    int last = arr[n];

    for(int i = n; i>=0; i--){
        arr[i] = arr[i-1];
    }

    arr[0] = last;

    cout << "The rotated array is: ";
    for(int num:arr){
        cout << num << " ";
    }

    cout << endl;

    return 0;
}