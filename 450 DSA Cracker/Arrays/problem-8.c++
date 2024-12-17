//------------------------------------
//      Minimize the Heights II
//      Link: https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,5,8,10};
    int k = 2;

    int n = arr.size();

    sort(arr.begin(), arr.end());

    int res = arr[n-1] - arr[0];

    for(int i = 1; i< n; i++){
        if(arr[i] - k < 0){
            continue;
        }

        int minH = min(arr[0] + k, arr[i] - k);
        int maxH = max(arr[i-1] + k, arr[n-1] - k);

        res = min(res, maxH - minH);
    }

    cout << "The maximum height possible is: " << res << endl;

    return 0;
}