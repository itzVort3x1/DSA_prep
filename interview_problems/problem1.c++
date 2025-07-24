//------------------------------------
//      Find the non repeating number in the array
//------------------------------------

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main() {
    vector<int> arr = {2,2,2,2,2,2,2,2,1,1,1,1,3};

    unordered_set<int> st;

    for(int n:arr){
        if(st.find(n) != st.end()){
            st.erase(n);
        }else {
            st.insert(n);
        }
    }

    unordered_set<int>::iterator itr;
  
    // Displaying set elements
    for (itr = st.begin(); 
        itr != st.end(); itr++) 
    {
        cout << *itr << " ";
    }

  return 0;

}