//------------------------------------
//      K-th element of two Arrays
//      Link: https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
//------------------------------------

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int a[] = {2,3,6,7,9};
    int b[] = {1,4,8,10};
    int n = 5;
    int m = 4;
    int i = 0;
    int j = 0;
    int ans = 0;
    int count = 0;
    int k = 5;

    while(true){
        int x1 = i < n ? a[i] : INT_MAX;
        int x2 = j < m ? b[j] : INT_MAX;

        if(x1 < x2){
            i++;
            ans = x1;
        }else {
            j++;
            ans = x2;
        }
        count++;
        if(count == k){
            cout << "The element at kth position is: " << ans << endl;
            return 0;
        }
    }

    cout << endl;
    return 0;
}