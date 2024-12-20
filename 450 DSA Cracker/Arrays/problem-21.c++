//------------------------------------
//      Maximum Product Subarray
//      Link: https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
//------------------------------------

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {-2,6,-3,-10,0,2};

    int n = arr.size();
    int productStart = 1;
    int productEnd = 1;
    int ans = INT_MIN;

    for(int i = 0; i<n; i++){
        productStart *= arr[i];
        productEnd *= arr[n-1-i];
        if(productStart==0)productStart=1;
        if(productEnd==0)productEnd=1;
        ans = max({ans, productStart, productEnd});
    }

    cout << "The max product is: " << ans << endl;

    return 0;
}