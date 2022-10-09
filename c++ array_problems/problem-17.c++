//------------------------------------
//      Check if two arrays are equal or not
//------------------------------------

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){

     vector<int> A;
     A.push_back(1);
     A.push_back(2);
     A.push_back(3);
     A.push_back(4);
     A.push_back(0);
     A.push_back(4);
     vector<int> B;
     B.push_back(2);
     B.push_back(4);
     B.push_back(5);
     B.push_back(0);
     B.push_back(1);
     B.push_back(4);

     if(A.size() != B.size()){
          cout << "The Array's are not equal" << endl;
     }

     map<int, int> mp;
     map<int, int> :: iterator itr;
     for(int i=0; i<6; i++){
          mp[A[i]]++;
     }
     // printing map;
     for(itr=mp.begin(); itr != mp.end(); itr++){
          cout<< (*itr).first << " " << (*itr).second << endl;
     }

     for(int i=0; i<6; i++){
          if(mp.find(B[i]) == mp.end()){
               cout << "The array's are not equal" << endl;
          }

          if(mp[B[i]] == 0){
               cout << "The array's are not equal" << endl;
          }
          mp[B[i]]--;
     }

     cout << "The Array's are equal" << endl;

     return 0;

}