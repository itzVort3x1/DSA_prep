//------------------------------------
//      Subarray of size k with given sum
//      Ex: Input : Arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20} , k = 4, sum = 18
//          Output :  YES
//------------------------------------

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int sum = 18;
    int n = 9;

    int curr_sum = 0;

    for(int i = 0; i<k; i++){
        curr_sum = curr_sum + arr[i];
    }

    if(curr_sum == sum){
        cout << "YES" << endl;
        return 0;
    }

    for(int i = k; i<n; i++){
        curr_sum = curr_sum + arr[i] - arr[i-k];

        if(curr_sum == sum){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;

}