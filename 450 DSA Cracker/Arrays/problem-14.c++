//------------------------------------
//      Common in 3 Sorted Arrays
//      Link: https://www.geeksforgeeks.org/problems/common-elements1132/1
//------------------------------------

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> arr1={1,5,10,20,40,80};
    vector<int> arr2={6,7,20,80,100};
    vector<int> arr3={3,4,15,20,30,70,80,120};

    set<int> st;
    int i,j,k;
    i=j=k=0;
    while(i < arr1.size() && j< arr2.size()&&k<arr3.size()){
        if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
            st.insert(arr1[i]);
            i++;j++;k++;
        }else if(arr1[i] < arr2[j]){
            i++;
        }else if(arr2[j] < arr3[k]){
            j++;
        }else {
            k++;
        }
    }

    for(int it:st){
        cout << it << ", ";
    }

    cout << endl;
    return 0;
}