#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

     //creation
     unordered_map<string, int> m;

     //insertion
     //1
     pair<string, int> p = make_pair("are", 3);
     m.insert(p);

     //2
     pair<string, int> q("hello", 2);
     m.insert(q);

     //3
     m["yours"] = 1;

     //search
     cout << m["yours"] << endl;
     cout << m.at("are") << endl;

     //using the at keyword for a key that is not present throws an error.
     // cout << m.at("unknownKey") << endl;
     //using this syntax for a key that is not present gives 0 as the answer.
     cout << m["unknownKey"] << endl;

     //size
     cout << m.size() << endl;

     //to check presence if it exists in the map
     cout << m.count("yours") << endl;

     //erase
     m.erase("are");
     cout << m.size() << endl;

     // first method of looping through the array.
     for(auto i:m){
          cout << i.first << " " << i.second << endl;
     }

     return 0;

}