//------------------------------------
//      Union of Arrays with Duplicates
//      Link: https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1
//------------------------------------

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {1,2,3};

    unordered_set<int> st;

    for(int num:a){
        st.insert(num);
    }

    for(int num:b){
        st.insert(num);
    }

    cout << "The size of the union is: " << st.size() << endl;

    return 0;
}