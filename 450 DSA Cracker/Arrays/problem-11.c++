//------------------------------------
//      Merge Without Extra Space
//      Link: https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
//------------------------------------

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {2, 4, 7, 10};
    vector<int> b = {2, 3};

    int i = a.size() - 1;
    int j = 0;

    while(i >=0 && j < b.size()){
        if(a[i] < b[j]){
            break;
        }
        swap(a[i], b[j]);
        i--;
        j++;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << "The sorted array is: " << endl;

    for(int num:a){
        cout << num << " ";
    }

    for(int num:b){
        cout << num << " ";
    }

    cout << endl;
    return 0;
}
